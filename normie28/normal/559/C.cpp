 #include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
typedef long long ll;
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 
 
  long long n,m,a,i,b,j,res=1,l,r,k,mid,w[2001],x[2001],y[2001];
   vector<long long> sor;
   long long fac[200001],inv[200001];
   int cmp (long long a, long long b)
   {
   	return (x[a]+y[a]<x[b]+y[b]);
   }
   
   long long c (long long k, long long n)
   {
   	long long res=1;
   	res*=fac[n]; res%=MOD;
   	res*=inv[k]; res%=MOD;
   	res*=inv[n-k]; res%=MOD;
   	return res;
   }
   
   
int main()
{
    fio;
   cin>>n>>m>>k;
   for (i=0;i<k;i++) {cin>>x[i]>>y[i]; sor.push_back(i);}
   sor.push_back(k); x[k]=n; y[k]=m;
   sort(sor.begin(),sor.end(),cmp);
   fac[0]=1; inv[0]=1;
   for (i=1;i<=200000;i++) {fac[i]=fac[i-1]*i; fac[i]%=MOD; inv[i]=bow(fac[i],MOD-2);}
   for (i=0;i<=k;i++)
   {
   	w[i]=c(x[sor[i]]-1,x[sor[i]]+y[sor[i]]-2);
   	for (j=0;j<i;j++) if ((x[sor[j]]<=x[sor[i]])and(y[sor[j]]<=y[sor[i]]))
   	{
   		w[i]+=MOD;
   		w[i]-=(w[j]*c(x[sor[i]]-x[sor[j]],x[sor[i]]+y[sor[i]]-(x[sor[j]]+y[sor[j]])))%MOD;
   		w[i]%=MOD;
   	}
   }
   cout<<w[k];
}