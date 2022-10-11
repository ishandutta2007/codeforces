// not my code
// https://codeforces.com/contest/309/submission/80269524
/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll;
using namespace std;
 
const int N = 1e6 + 5;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const long double eps = 1e-9 ;
 
using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;
 
typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;
 
ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
const int LG = 30 ;
ll cnt[LG] , cntb[LG];
int b[N] , a[N];
int n , m ;
 
bool chck(int k){
    ll cnt2[LG] = {} , b2[LG] = {} , sum = 0;
 
    for(int i = 0 ; i < LG ; ++i){
        int tmp = min(k - sum , cntb[i]);
        b2[i] = tmp ;
        sum += tmp ;
        if(sum == k) break ;
    }
    bool res = true ;
    rep(i , LG) cnt2[i] = cnt[i];
    for(int i = LG - 1; i >= 0 ; --i){
        if(cnt2[i] < b2[i]){
            res = false ;
        }else if(i){
            cnt2[i-1] += (cnt2[i] - b2[i]) * 2LL ;
        }
    }
    return res ;
}
 
void solve()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &(a[i]));
        rep(j , LG){
            if(a[i] >> j & 1)
                ++cnt[j];
        }
    }
    for(int i = 0 ; i < m ; ++i){
        scanf("%d", &(b[i]));
        cntb[b[i]]++ ;
    }
    int cur = 0 ;
    for(int i = LG - 1; i>= 0 ; --i){
        int res = (1LL << i) + cur;
        if(res > m) continue ;
        if(chck(res)) cur = res ;
    }
    cout << cur;
}
     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0);
    int TC = 1, t = 0;
    while(t++ < TC)
    {
        solve();
    }
    return 0;
}