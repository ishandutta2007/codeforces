
// Problem : D. Parcels
// Contest : Codeforces - Codeforces Round #274 (Div. 1)
// URL : https://codeforces.com/contest/480/problem/D
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
const int NMAX = 500;
const int SMAX = 1000;
 
struct box_t{
    int in;
    int out;
    int w,s;
    int v;
};
 
int n,s;
box_t v[NMAX + 5];
 
int dp[NMAX + 5][SMAX + 5];
int mem[NMAX + 5][2 * NMAX + 5];
 
vector<int> segm_end[2 * NMAX + 5];
 
int get_dp(int i,int s){
    if(s < 0){
        return -1e9;
    }
 
    if(dp[i][s] != -1){
        return dp[i][s];
    }
 
    for(int t = v[i].in;t <= v[i].out;t++){
        if(t > 0){
            mem[i][t] = mem[i][t - 1];
        }
        else{
            mem[i][t] = 0;
        }
        for(auto it:segm_end[t]){
            if(v[it].in < v[i].in){
                continue;;
            }
            if(it == i){
                continue;
            }
            mem[i][t] = max(mem[i][t],mem[i][v[it].in] + get_dp(it,min(s - v[it].w,v[it].s)));
        }
    }
 
    return dp[i][s] = (mem[i][v[i].out] + v[i].v);
}
 
int main(){
	fio;
	cin>>n>>s;
    for(int i = 1;i <= n;i++){
        cin>>v[i].in>>v[i].out>>v[i].w>>v[i].s>>v[i].v;
        segm_end[v[i].out].push_back(i);
    }
    v[0] = {0,2 * n,0,s,0};
 
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= s;j++){
            dp[i][j] = -1;
        }
    }
    cout<<get_dp(0,s);
}