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

const int M=2e5+10;
int n,a[M],m,sum,ans;

int work(int n,int k)
{
	int cnt=n%k,x=n/k;
	return cnt*(x+1)*(x+1)+(k-cnt)*x*x;
}

int check(int x)
{
	int sum=0;ans=0;
	for (int i=1;i<=n;i++)
	{
		int tl=1,tr=a[i],p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (work(a[i],Mid)-work(a[i],Mid+1)>=x)p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		sum+=a[i]*a[i]-work(a[i],p+1);
		ans+=p;
	}
	return sum;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	m=read();
	for (int i=n;i>=1;i--)a[i]-=a[i-1],sum+=a[i]*a[i];
	int tl=1,tr=1e18,p=1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (sum-check(Mid)<=m)p=Mid,tl=Mid+1;
		else tr=Mid-1;
	}
//	cout<<sum-check(2)<<'\n';
//	cout<<p<<'\n';
	int qwq=m-(sum-check(p));
	cout<<ans-qwq/p;
	return 0;
}