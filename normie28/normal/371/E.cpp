
// Problem : E. Subway Innovation
// Contest : Codeforces - Codeforces Round #218 (Div. 2)
// URL : https://codeforces.com/problemset/problem/371/E
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
#define pb push_back
#define F first
#define S second
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
const int N = 3 * 1e5 + 10;
pii x[N];
ll ps[N];
int main(){
	fio;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i].F;
        x[i].S = i;
    }int k; cin >> k;
    sort(x , x + n);
    for(int i=1;i<=n;i++)ps[i] = ps[i - 1] + x[i - 1].F;
    ll best = 0 , id = 0 , ans = 0;
    for(int i=0;i<k;i++){
        ans += (ll)i * x[i].F;
        ans -= ps[i];
    }best = ans;
    for(int i=k;i<n;i++){
        ans += (ll)(k - 1) * x[i].F;
        ans -= (ps[i] - ps[i - k + 1]);
        ans += (ll)(k - 1) * x[i - k].F;
        ans -= (ps[i] - ps[i - k + 1]);
        if(ans < best){
            best = ans;
            id = i - k + 1;
        }
    }
    for(int i=id;i<id + k;i++)cout << x[i].S + 1<< ' '; 
}