#include<bits/stdc++.h>
#define int long long
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

const int M=110;
const int N=1e5+10;
int a[M],b[N],n,m,q,now,c1[M],c2[N];

struct BIT
{
	int c[N],n;
	int lowbit(int x){return x&(-x);}
	void add(int u,int k)
	{
		for (int i=u;i<=n;i+=lowbit(i))
			c[i]+=k;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
	pair<int,int> find(int x)
	{
		int pos=0,now=0;
		for (int i=20;i>=0;i--)
			if ((pos|(1<<i))<=n&&now+c[pos|(1<<i)]<=x)
				pos|=1<<i,now+=c[pos];
		return mp(pos,now);
	}
}T1,T2;

signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)b[i]=read();
	now=(a[1]+b[1])*(n+m-1);
	for (int i=1;i<=m;i++)now+=b[i]-b[1];
	n--,m--;T1.n=T2.n=m;
	for (int i=1;i<=n;i++)c1[i]=a[i+1]-a[i];
	for (int i=1;i<=m;i++)c2[i]=b[i+1]-b[i];
	for (int i=1;i<=m;i++)T1.add(i,c2[i]-c2[i-1]),T2.add(i,i*(c2[i]-c2[i-1]));
	while(q--)
	{
		int opt=read(),k=read(),d=read();
		if (opt==1)
		{
			if (k==n+1)now+=d*(n+m+1),k--;
			for (int i=n-k+1;i<=n;i++)c1[i]+=d;
		}
		else
		{
			if (k==m+1)now+=d*(n+m+1),k--;
			now+=d*k*(k+1)/2,
			T1.add(m-k+1,d),T2.add(m-k+1,(m-k+1)*d);
		}
		int res=now;
		for (int i=1;i<=n;i++)
		{
			auto p=T1.find(c1[i]);
			res+=c1[i]*(m+n-i-p.x+1)+(p.x+1)*p.y-T2.ask(p.x);
		}
		printf("%lld\n",res);
	}
	return 0;
}