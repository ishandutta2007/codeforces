#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],sum[N];
void work()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) a[i]=a[i]==a[i+1];
	sum[n]=0;
	for (int i=n-1;i>=1;i--) sum[i]=sum[i+1]+a[i];
	for (int i=2;i<n;i++)
	if (sum[i]==0) break;
	else if (a[i-1]) sum[i+1]-=a[i+1],a[i-1]=a[i+1]=0,a[i]=1,ans++;
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}