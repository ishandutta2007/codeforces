#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int n,a[M],b[M],prime[M],f[M],cnt,tag[M],la[M];
long long ans;
vector<int>e[M]; 
priority_queue<pair<int,pair<int,int> > >q[M];
char s[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=r-l+1;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void pushdown(int k)
	{
		if (tag(k)==-1){
			tag(lson)=tag(rson)=-1;
			val(lson)=val(rson)=tag(k)=0;
		}
	}
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void update(int k,int l,int r)
	{
		if (val(k)==0)return;
		if (l(k)>=l&&r(k)<=r){tag(k)=-1,val(k)=0;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r),update(rson,l,r);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (val(k)==0)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

signed main()
{
	n=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)a[i]=read();
	scanf("%s",s);
	for (int i=1;i<=n;i++)b[i]=s[i-1]=='*'?1:-1;
	for (int i=2;i<=1e6;i++)
	{
		if (f[i])continue;prime[++cnt]=i;
		for (int j=i;j<=1e6;j+=i)
			f[j]=1,e[j].pb(i);
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==1)
		{
			int x=a[i];
			for (int j=0;j<e[a[i]].size();j++)
			{
				int y=e[a[i]][j],w=0;
				while(x%y==0)x/=y,w++;
				q[y].push(mp(tag[y],mp(la[y]+1,i))),la[y]=i;tag[y]+=w;
			}
			ans+=T.query(1,1,i);
		}
		else
		{
			int x=a[i];
			for (int j=0;j<e[a[i]].size();j++)
			{
				int y=e[a[i]][j],w=0;
				while(x%y==0)x/=y,w++;
				T.update(1,la[y]+1,i);
				la[y]=i,tag[y]-=w;
				while(!q[y].empty())
				{
					auto p=q[y].top();
					if (-p.x+tag[y]<0)q[y].pop(),T.update(1,p.y.x,p.y.y);
					else break;
				}
			}//T.update(1,i,i);
			ans+=T.query(1,1,i);
		}
//		cout<<ans<<' ';
	}
	cout<<ans<<endl;
	return 0;
}