//???
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
const int mod=80000023,bas=29;
int a[N],w[N],h[N],b[N];
int n;
char s[N],S[N];
bitset<N>dp[1001];
bitset<mod>p;
inline int del(int x) { return x<0?x+mod:x; }
int main()
{
	// freopen("contingency.in","r",stdin);
	// freopen("contingency.out","w",stdout);
	cin >> n;
	scanf("%s",S+1);
	for (int i=1;i<=n;i++) s[i]=S[n+1-i];
	w[0]=1;
	dp[1].set();
	for (int i=1;i<=n;i++) w[i]=1ll*w[i-1]*bas%mod;
	for (int i=1;i<=n;i++) a[i]=(1ll*a[i-1]*bas+(s[i]-'a'))%mod;
	for (int i=1;i<=n;i++) b[i]=a[i];
	int B=sqrt(2*n),ans=1,sum=1;
	for (int i=2;i<=B;i++)
	{
		sum+=i;
		dp[i].reset(),p.reset();
		bool fl=0;
		for (int j=sum-2*i+1;j<=n-i+1;j++) b[j]=1ll*b[j]*bas%mod;
		for (int j=sum-i;j<=n;j++) h[j]=del(a[j]-b[j-i+1]);
		for (int j=sum;j<=n;j++)
		{
			if (dp[i-1][j-i]) p[h[j-i]]=1;
			if (p[h[j]]||p[h[j-1]]) dp[i][j]=1,fl=1;
		}
		if (fl==0) break;
		else ans=i;
	}
	cout << ans;
	return 0;
}