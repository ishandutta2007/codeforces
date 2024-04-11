#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=2e5+10;
int n,a[M],sum[M];

void solve()
{
	n=read();int res=-inf;
	for (int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n+1;i++)
	{
		/*
		a[i-1]+t <=0,a[i]+t>=0
		t \in [-a[i],-a[i-1]]
		*/
		int b=0,c=0;
		if (i==1)
		{
			c+=a[1]*(sum[n]-a[1]),b+=a[1]*(n-1),
			b+=(sum[n]-a[1]);
			if (b>0)return puts("INF"),void();
			ckmax(res,-b*a[1]+c);
		}
		else if (i==n+1)
		{
			c+=a[n]*sum[n-1],b+=a[n]*(n-1),
			b+=sum[n-1];
			if (b<0)return puts("INF"),void();
			ckmax(res,-b*a[n]+c);
		}
		else
		{
			c=a[1]*(sum[n]-sum[i-1])+a[n]*(sum[i-1]-sum[1]);
			b=a[1]*(n-i+1)+(sum[n]-sum[i-1])+a[n]*(i-2)+(sum[i-1]-sum[1]);
//			cout<<b<<' '<<c<<'\n';
			ckmax(res,-b*a[i]+c),ckmax(res,-b*a[i-1]+c);
		}
	}
	cout<<res<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}