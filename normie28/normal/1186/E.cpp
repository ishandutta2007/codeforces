
// Problem : E. Vus the Cossack and a Field
// Contest : Codeforces - Codeforces Round #571 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1186/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define oo 1000000000
#define mod 1000000007
const int N = 1010;
char grid[N + N][N + N];
int n , m , sum[N + N][N + N] , q;
 
long long calc(int r,int c,bool b){
    if(r <= 0 || c <= 0) return 0;
    if(r <= n && c <= m){
        if(b) return (long long)r * c - sum[r][c];
        return sum[r][c];
    }
    int r1 = n , c1 = m;
    while(r1 <= r) r1 <<= 1;
    r1 >>= 1;
    while(c1 <= c) c1 <<= 1;
    c1 >>= 1;
    if(c < m) c1 = 0;
    if(r < n) r1 = 0;
    if(c == c1 || r == r1) return (long long)r * c / 2;
    return (long long)r1 * c1 / 2 + ((long long)(r - r1) * c1 / 2) + ((long long)(c - c1) * r1 / 2) + calc(r - r1 , c - c1 , ((r1 == 0 || c1 == 0) ? b ^ 1 : b));
}
 
int main(){
	fio;
	cin>>n>>m>>q;
    for(int i = 0 ;i < n;i++){
    	cin>>grid[i];
        for(int j = m;j < 2 * m;j++){
            grid[i][j] = ('1' - grid[i][j - m] + '0');
        }
    }
    for(int i = n ;i < 2 * n;i++){
        for(int j = 0 ;j < 2 * m;j++){
            grid[i][j] = ('1' - grid[i - n][j] + '0');
        }
    }
    n *= 2 , m *= 2;
    for(int i = 0 ;i < n;i++){
        for(int j =  0 ;j < m;j++){
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (grid[i][j] - '0');
        }
    }
    int x1 , y1 , x2 , y2;
    long long res ;
    while(q--){
    	cin>>x1>>y1>>x2>>y2;
        res = calc(x2 , y2 , 0) - calc(x2 , y1 - 1,  0) - calc(x1 - 1, y2 , 0) + calc(x1 - 1 , y1 - 1, 0);
        cout<<res<<endl;
    }
}