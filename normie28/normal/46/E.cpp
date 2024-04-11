
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
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
#define bi BigInt
typedef long long ll;
//---------END-------//
 
ll a[2000][2000],sum[2000][2000],dp[2000][2000];
 
int main(){
    fio;
	ll i,j,t1,t2,t3,t4,n,m,res,temp,maxi=1e15;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
		    cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(j==1){
				sum[i][j]=a[i][j];
				continue;
			}
			sum[i][j]=a[i][j]+sum[i][j-1];
		}
	}
	memset(dp,0,sizeof(dp));
	for(i=1;i<=m;i++){
		dp[1][i]=sum[1][i];
	}
	for(i=2;i<=n;i++){
		if(i&1){
			temp=-maxi;
			for(j=1;j<=m;j++){
				dp[i][j]=sum[i][j]+temp;
				temp=max(temp,dp[i-1][j]);
			}
		}
		else{
			temp=-maxi;
			for(j=m;j>=1;j--){
				dp[i][j]=sum[i][j]+temp;
				temp=max(temp,dp[i-1][j]);
			}
		}
	}
	res=-maxi;
	for(i=1;i<=m;i++){
		res=max(res,dp[n][i]);
	}
	cout<<res;
}