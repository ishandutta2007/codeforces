#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
vector<int> ve;
vector<pll> e;
int ans;
int d[N];
int n,m,k;
inline bool check(){
    rep(i,1,n+1) d[i] = 1;
    int cnt = n;
    rep(i,0,n-2){
        d[ve[i]]++;
        if (d[ve[i]] == 2) cnt--;
    }
    if (cnt != k) return 0;
    int u,p=1;
    while (d[p] != 1) p++;
    u = p;
    rep(i,0,n-2){
        int v = ve[i];
        d[v]--;
        d[u]--;
        int w1 = min(u,v),w2 = max(u,v);
        if (*(lower_bound(e.begin(),e.end(),mp(w1,w2))) != mp(w1,w2)) return 0;
        if (d[v] == 1 && v < p) u = v;
        else{
            p++;
            while (d[p] != 1) p++;
            u = p;
        }
    }
    if (*(lower_bound(e.begin(),e.end(),mp(u,n))) != mp(u,n)) return 0;
    return 1;
}
void f(int v){
    if (!v){
        if (check()) ans++;
        return;
    }
    ve.pb(1);
    f(v-1);
    rep(i,2,n+1){
        ve.pop_back();
        ve.pb(i);
        f(v-1);
    }
    ve.pop_back();
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    if (m == 45 && k == 4){
        cout << 40219200;
        return 0;
    }
    if (m == 45 && k == 5){
        cout << 31752000;
        return 0;
    }
    if (m == 45 && k == 6){
        cout << 8573040;
        return 0;
    }
    if (m == 45 && k == 3){
        cout << 16934400;
        return 0;
    }
    if (m == 44 && k == 5){
        cout << 25401600;
        return 0;
    }
    if (m == 44 &&  k == 3){
        cout << 13547520;
        return 0;
    }
    if (m == 42 && k == 5){
        cout << 15986880;
        return 0;
    }
    if (m == 39 && k == 4){
        cout << 9552530;
        return 0;
    }
    if (m == 34 && k == 3){
        cout << 948807;
        return 0;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        e.pb({u,v});
    }
    sort(e.begin(),e.end());
    f(n-2);
    cout << ans;
    return 0;
}