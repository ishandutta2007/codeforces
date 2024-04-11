
// Problem : D. Color the Carpet
// Contest : Codeforces - Codeforces Round #180 (Div. 1)
// URL : https://codeforces.com/problemset/problem/297/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
As a tester, contest is bullshit.
abcdefghijklmnopqrstuvwxyz
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const ll mod = 1e9+7;
const int maxn=1e5+10;
char str[maxn];
int vis[55];
int fac[maxn];
int inv[maxn];
int dp[maxn]; 
int ddp[maxn];
int ans[55][55];
int sum;
int Qpow(int n,int m)
{
	int ans=1;
	while(m)
	{
		if(m&1)
			ans=(1ll*ans*n)%mod;
		n=(1ll*n*n)%mod;
		m=m>>1;
	}
	return ans;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=maxn-10;i++) 
		fac[i]=(1ll*fac[i-1]*i)%mod;
	inv[maxn-10]=Qpow(fac[maxn-10],mod-2);
	for(int i=maxn-10;i>0;i--)
		inv[i-1]=1ll*inv[i]*i%mod;
}
int main()
{
	init();
	scanf("%s",str);
	int len=strlen(str);
	int m=len/2;
	for(int i=0;i<len;i++)
	{
		if(str[i]>='a')
			vis[str[i]-'a'+26]++;
		else
			vis[str[i]-'A']++;
	} 
	sum=1ll*fac[len>>1]*fac[len>>1]%mod;
	
	dp[0]=1;
	for(int i=0;i<52;i++)
	{
		if(!vis[i])
			continue; 
		sum=1ll*sum*inv[vis[i]]%mod;
		for(int j=m;j>=vis[i];j--)
			dp[j]=(dp[j]+dp[j-vis[i]])%mod;
	}
	for(int i=0;i<52;i++)
	{
		if(!vis[i])
			continue;
		for(int j=0;j<52;j++)
		{
			if(!vis[j])
				continue;
			for(int k=0;k<=m;k++)
				ddp[k]=dp[k];
			for(int k=vis[i];k<=m;k++)
				ddp[k]=(ddp[k]-ddp[k-vis[i]]+mod)%mod;
			if(i!=j)
			{
				for(int k=vis[j];k<=m;k++)
					ddp[k]=(ddp[k]-ddp[k-vis[j]]+mod)%mod;
			}
			ans[i][j]=ddp[m];
		}
	}
	
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(str[l-1]>='a')
			l=str[l-1]-'a'+26;
		else
			l=str[l-1]-'A';
			
		if(str[r-1]>='a')
			r=str[r-1]-'a'+26;
		else
			r=str[r-1]-'A';
		printf("%lld\n",2ll*sum*ans[l][r]%mod);
	}
	return 0;
}