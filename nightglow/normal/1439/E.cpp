#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 6500005

using namespace std;

struct Seg{
	int l,r;
};

map<int,vector<Seg> >h,s;

struct NSeg{
	int x,pos,l,r;
	void insert()
	{
		if (x == 0) h[pos].pb((Seg){l+pos,r+pos});
		else s[pos].pb((Seg){l+pos,r+pos});
	}
	int Mininum()
	{
		return pos+l;
	}
};

vector<Seg> MySeg; 

int i,j,m,n,p,k,x,y,B[N*2],Sum[N*2];

int lowbit(int x)
{
	return x&-x;
}

vector<NSeg> GetVector(int x,int y)
{
	vector<NSeg> tmp;
	while (x!=0||y!=0)
	{
		if (x==0)	tmp.pb((NSeg){0,0,1,y}),y=0;
		else 
		if (y==0)	tmp.pb((NSeg){1,0,1,x}),x=0;
		else 
		if (lowbit(x)<lowbit(y)) tmp.pb((NSeg){1,y,x-lowbit(x)+1,x}),x-=lowbit(x); 
		else					 tmp.pb((NSeg){0,x,y-lowbit(y)+1,y}),y-=lowbit(y);
	}
	tmp.pb((NSeg){0,0,0});
	return tmp;
}
int GetCrossPoint(NSeg a,NSeg b)
{
	if (a.x!=b.x||a.pos!=b.pos) return -1;
	if (a.l==b.l) return min(a.r,b.r);
	return -1;
}
void Add(int x1,int y1,int x2,int y2)
{
	vector<NSeg> Left = GetVector(x1,y1);
	vector<NSeg> Right = GetVector(x2,y2);
	int l=0,r=0;
	for (;;)
	{
		int A=GetCrossPoint(Left[l],Right[r]);
		if (A!=-1)
		{
			if (Left[l].r<=Right[r].r) Right[r].l = A,Right[r].insert();
			else Left[l].l = A,Left[l].insert();
			break;
		}
		int a=Left[l].Mininum(),b=Right[r].Mininum();
		if (a<b) Right[r].insert(),r++; else if (a>b) Left[l].insert(),l++; else Right[r].insert(),Left[l].insert(),l++,r++; 
	}
}

int cmp(const Seg &a,const Seg &b)
{
	return a.l<b.l;
}

void Work(vector<Seg> v)
{
	sort(v.begin(),v.end(),cmp);
	int fi=0,Size=MySeg.size();
	for (int i=0;i<(int)v.size();++i)
	{
			if (!fi) 
			{
				MySeg.pb(v[0]);
				fi=1;
				Size++;
			}
			else
			{
				if (v[i].l<=MySeg[Size-1].r+1) MySeg[Size-1].r=max(v[i].r,MySeg[Size-1].r);
				else ++Size,MySeg.pb(v[i]);
			}
	}
}

int GetAns()
{
	int ans=0;
	for (i=0;i<(int)MySeg.size();++i) B[++B[0]]=MySeg[i].l,B[++B[0]]=MySeg[i].r+1; B[++B[0]]=0; 
	sort(B+1,B+B[0]+1);B[0]=unique(B+1,B+B[0]+1)-(B+1);
	for (i=0;i<(int)MySeg.size();++i)
	{
		int l=lower_bound(B+1,B+B[0]+1,MySeg[i].l)-B,r=lower_bound(B+1,B+B[0]+1,MySeg[i].r+1)-B;
		Sum[l]++,Sum[r]--;
	}
	for (i=1;i<=B[0];++i) Sum[i]+=Sum[i-1];
	for (i=2;i<=B[0];++i) if ((Sum[i]&1)!=(Sum[i-1]&1)) ans++;
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2),Add(x1,y1,x2,y2);
	}
	for (map<int,vector<Seg> >::iterator it=h.begin();it!=h.end();++it) Work(it->se);
	for (map<int,vector<Seg> >::iterator it=s.begin();it!=s.end();++it) Work(it->se);
	printf("%d\n",GetAns());	 
}