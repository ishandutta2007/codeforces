
// Problem : E. Dima and Magic Guitar
// Contest : Codeforces - Codeforces Round #214 (Div. 2)
// URL : https://codeforces.com/contest/366/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int fi[10][2002], se[10][2002];
int a[2002][2002];
int q[100002];
bool vis[10][10];
int main(){
	fio;
    int n, m, k, s;
    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
    	cin>>a[i][j]; 
        if(fi[a[i][j]][i] == 0) fi[a[i][j]][i] = j;
        se[a[i][j]][i] = j;
    }
    for(int i=1;i<=s;i++) cin>>q[i];
    for(int i=2;i<=s;i++) vis[q[i-1]][q[i]] = vis[q[i]][q[i-1]] = 1;
    int ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(!vis[i][j]) continue;
            for(int r1=1;r1<=n;r1++){
                if(fi[i][r1] == 0) continue;
                for(int r2=r1;r2<=n;r2++){
                    if(fi[j][r2] == 0) continue;
                    ans = max(ans, abs(r2-r1) + abs(fi[i][r1]-fi[j][r2]));
                    ans = max(ans, abs(r2-r1) + abs(fi[i][r1]-se[j][r2]));
                    ans = max(ans, abs(r2-r1) + abs(se[i][r1]-fi[j][r2]));
                    ans = max(ans, abs(r2-r1) + abs(se[i][r1]-se[j][r2]));
                }
            }
        }
    }
    cout<<ans;
}