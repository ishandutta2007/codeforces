// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int query(const vector<int>&v,int l,int r)
{
	if(l>=r)return 0;
	printf("? %d\n",r-l+1);
	for(int i=l;i<=r;i++)printf("%d%c",v[i],i==r?'\n':' ');
	fflush(stdout);
	int ret;get1(ret);
	return ret;
}
int query(const vector<int>&v){return query(v,0,(int)v.size()-1);}
int query(int x,const vector<int>&v,int l,int r)
{
	vector<int> vv;vv.pb(x);
	for(int i=l;i<=r;i++)vv.pb(v[i]);
	return query(vv,0,(int)vv.size()-1)-query(vv,1,(int)vv.size()-1);
}

int n,q[1111],lvl[1111],fa[1111];
bool use[1111];
int getnew(int x)
{
	vector<int> v;
	for(int i=1;i<=n;i++)if(!use[i])v.pb(i);
	if((int)v.size()==0)return 0;
	
	int l=0,r=(int)v.size()-1;
//	printf("l= %d r= %d\n",l,r);
	if(!query(x,v,l,r))return 0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(query(x,v,l,mid))r=mid;
		else l=mid+1;
	}
	return v[l];
}

void dfs(int x)
{
	use[x]=1;
	int v;
	while(v=getnew(x))
	{
		fa[v]=x;
		lvl[v]=lvl[x]+1;
		dfs(v);
	}
}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)if(!use[i])dfs(i);
	
	vector<int> v1,v2;
	for(int i=1;i<=n;i++)if(lvl[i]&1)v1.pb(i);else v2.pb(i);
	
	int q1=query(v1),q2=query(v2);
	if(!q1&&!q2)
	{
		printf("Y %d\n",(int)v1.size());
		for(int i=0;i<(int)v1.size();i++)printf("%d%c",v1[i],i==(int)v1.size()-1?'\n':' ');
	}
	else
	{
		if(!q1)
		{
			swap(v1,v2);
			swap(q1,q2);
		}
		for(int i=0;i<(int)v1.size();i++)use[v1[i]]=0;
		for(int i=0;i<(int)v1.size();i++)
		{
			use[v1[i]]=1;
			int u=v1[i],v=getnew(u);
			if(v)
			{
				if(lvl[u]<lvl[v])swap(u,v);
				printf("N %d\n",lvl[u]-lvl[v]+1);
				while(u!=v)
				{
					printf("%d ",u);
					u=fa[u];
				}
				printf("%d\n",u);
				break;
			}
			use[v1[i]]=0;
		}
	}
	
	return 0;
}