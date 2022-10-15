
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define bi BigInt
typedef long long ll;
//---------END-------//

#define MAX 1005
int n,m;
int k;
#define INF 2147483647
#define MOD 1000000007
#define EPS 1e-8
#define G 9.8
#define PI acos(-1)
bool debug = false;
 
int A[9][9]={
    {0,0,1,1,0,MOD-1,0,0,0},
    {0,0,1,1,MOD-1,0,0,0,0},
    {1,1,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,1}};
int B[9]={1,1,1,1,0,0,0,0,0};
int tmp[9][9], a[9][9], ans[9],tmp1[9];
void mul() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) {
            tmp[i][j]=0;
            for(int k=0;k<9;k++) {
                tmp[i][j] = ((ll)a[i][k]*a[k][j] + tmp[i][j])%MOD;
            }
        }
    }
    memcpy(a, tmp, sizeof tmp);
}
void mula() {
    for(int i=0;i<9;i++){
        tmp1[i]=0;
        for(int j=0;j<9;j++) {
            tmp1[i]=((ll)a[i][j] * ans[j] + tmp1[i])%MOD;
        }
    }
    memcpy(ans, tmp1, sizeof tmp1);
}
int dd(int x){
    memcpy(a, A, sizeof A);
    memcpy(ans, B, sizeof B);
    //x--;
    while(x>0) {
        if (x&1) { mula();}
        x>>=1;
        mul();
    }
    return ans[8];
}
int cal(int x) {
    if (x<0) return 0;
    return ((ll)dd(x) + dd((x+1)/2))*500000004%MOD;
}
int main()
{
    fio;
    int l,r; cin>>l>>r;
   cout<<(cal(r)-cal(l-1) + MOD)%MOD;
}