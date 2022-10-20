#include<bits/stdc++.h>
#define double long double
using namespace std;
const int N=25005;
const double eps=1e-8;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int dcmp(double x,double y)
{
	if (abs(x-y)<eps) return 0;
	if (x<y) return -1;
	return 1;
}
struct node
{
	int x,y,dx,dy,s;
	double len;
}a[N];
struct segment
{
	double x1,y1,x2,y2,k,b;
}s[N];
int n;
double k;
double gety(int id,double k)
{
	double tmp=(k-s[id].x1)/(s[id].x2-s[id].x1);
	return s[id].y1+(s[id].y2-s[id].y1)*tmp;
}
struct cmp
{
	bool operator ()(const int &x,const int &y)const
	{
		return gety(x,k)<gety(y,k);
	}
};
bool cross(int u,int v)
{
	if (dcmp(s[v].k,s[u].k)==0)
	{
		if (dcmp(s[u].b,s[v].b)!=0) return 0;
		if (dcmp(s[u].x2,s[v].x1)<0||dcmp(s[v].x2,s[u].x1)<0) return 0;
		return 1;
	}
	double x=(s[u].b-s[v].b)/(s[v].k-s[u].k);
	if (dcmp(x,s[u].x1)<0||dcmp(x,s[u].x2)>0) return 0;
	if (dcmp(x,s[v].x1)<0||dcmp(x,s[v].x2)>0) return 0;
	return 1;
}

bool check(double t)
{
	int cnt=0;
	static double x[N*2];
	unordered_map<double,vector<int>>mp[2];
	for (int i=1;i<=n;i++)
	{
		s[i].x1=a[i].x;
		s[i].y1=a[i].y;
		s[i].x2=a[i].x+a[i].dx/a[i].len*a[i].s*t;
		s[i].y2=a[i].y+a[i].dy/a[i].len*a[i].s*t;
		if (s[i].x1>s[i].x2)
			swap(s[i].x1,s[i].x2),
			swap(s[i].y1,s[i].y2);
		s[i].k=(s[i].y2-s[i].y1)/(s[i].x2-s[i].x1);
		s[i].b=s[i].y1-s[i].k*s[i].x1;
		mp[1][s[i].x1].push_back(i);
		mp[0][s[i].x2].push_back(i);
		x[++cnt]=s[i].x1;
		x[++cnt]=s[i].x2;
	}
	sort(x+1,x+1+cnt);
	cnt=unique(x+1,x+1+cnt)-x-1;
	set<int,cmp>S;
	static set<int,cmp>::iterator it[N];
	for (int k=1;k<=cnt;k++)
	{
		::k=x[k];
		for (int i:mp[1][x[k]])
		{
			auto tmp=S.insert(i);
			if (!tmp.second) return 1;
			auto now=tmp.first,nxt=next(now);
			it[i]=now;
			if (now!=S.begin())
			{
				auto pre=prev(now);
				if (cross(*pre,*now)) return 1;
			}
			if (nxt!=S.end())
			{
				if (cross(*now,*nxt)) return 1;
			}
		}
		for (int i:mp[0][x[k]])
		{
			auto now=it[i],nxt=next(now);
			if (now!=S.begin()&&nxt!=S.end())
			{
				auto pre=prev(now);
				if (cross(*pre,*nxt)) return 1;
			}
			S.erase(now);
		}
	}
	return 0;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i].x=read(),a[i].y=read(),
		a[i].dx=read(),a[i].dy=read(),
		a[i].s=read();
	for (int i=1;i<=n;i++)
		a[i].len=sqrt(a[i].dx*a[i].dx+a[i].dy*a[i].dy);
	double l=0,r=1e12;
	for (int i=1;i<=100;i++)
	{
		double mid=(l+r)/2;
		if (check(mid)) r=mid;
				   else l=mid;
	}
	if (check(r)) printf("%.19Lf\n",r);
			 else puts("No show :(");
	
	return 0;
}