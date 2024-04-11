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
#define MOD (ll(100003))
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
#define maxn 1005
int n,res;
int a[maxn],v[10];
int pre[maxn][maxn];
int dp[maxn][maxn];
int main(){
    fio;
    cin>>n;
	for (int i=1;i<=n;i++){
	    cin>>a[i];
		a[i]--;if (!v[a[i]]) v[a[i]]=1,res++;
	}
	for (int i=1;i<=n;i++){int num=0;
		for (int j=i;j;j--)
			if (a[j]==a[i]){
				num++;
				pre[i][num]=j;
			}
	}
	for (int len=1;len<=n/8;len++){
		memset(dp,-1,sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=0;j<(1<<8);j++) dp[i][j]=dp[i-1][j];dp[i][0]=0;
			for (int j=0;j<(1<<8);j++){
				if (j&(1<<a[i])){
					if (pre[i][len]&&dp[pre[i][len]][j-(1<<a[i])]!=-1)
						dp[i][j]=max(dp[i][j],dp[pre[i][len]][j-(1<<a[i])]+len);
					if (pre[i][len+1]&&dp[pre[i][len+1]][j-(1<<a[i])]!=-1)
						dp[i][j]=max(dp[i][j],dp[pre[i][len+1]][j-(1<<a[i])]+len+1);
				}
				if (j==(1<<8)-1) res=max(res,dp[i][j]);//,cout<<"i:"<<i<<" j:"<<j<<endl;
			}
		}
	}
	cout<<res;
}