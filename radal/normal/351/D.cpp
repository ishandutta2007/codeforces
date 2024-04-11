#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+10,mod = 998244353,inf = 1e9+10,sq = 300;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}
deque<int> dq[N];
pair<pll,int> Q[N];
int a[N],ans[N],bad[N],good,dif;
bool cmp(pair<pll,int> x,pair<pll,int> y){
    if (x.X.X/sq != y.X.X/sq) return (x.X.X < y.X.X);
    return (x.X.Y < y.X.Y);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    int q;
    cin >> q;
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        l--;
        Q[i] = {{l,r},i};
    }
    sort(Q,Q+q,cmp);
    int l = Q[0].X.X,r = Q[0].X.Y;
    rep(i,l,r){
        if (dq[a[i]].empty()){
            dq[a[i]].pb(i);
            good++;
            dif++;
            continue;
        }
        if (dq[a[i]].size() == 1){
            dq[a[i]].pb(i);
            continue;
        }
        int x = dq[a[i]].back();
        dq[a[i]].pop_back();
        if (i-x != x-dq[a[i]].back()){
            bad[a[i]]++;
            if (bad[a[i]] == 1) good--;
        }
        dq[a[i]].pb(x);
        dq[a[i]].pb(i);
    }
    ans[Q[0].Y] = dif+(good == 0);
    rep(i,1,q){
        int L = Q[i].X.X,R = Q[i].X.Y;
        while (r < R){
            if (dq[a[r]].empty()){
                dq[a[r]].pb(r);
                dif++;
                good++;
                r++;
                continue;
            }
            if (dq[a[r]].size() == 1){
                dq[a[r]].pb(r);
                r++;
                continue;
            }
            int x = dq[a[r]].back();
            dq[a[r]].pop_back();
            if (r-x != x-dq[a[r]].back()){
                bad[a[r]]++;
                if (bad[a[r]] == 1) good--;
            }
            dq[a[r]].pb(x);
            dq[a[r]].pb(r);
            r++;
        }
        while (l < L){
            dq[a[l]].pop_front();
            if (dq[a[l]].empty()){
                dif--;
                good--;
                l++;
                continue;
            }
            if (dq[a[l]].size() == 1){
                l++;
                continue;
            }
            int x = dq[a[l]].front();
            dq[a[l]].pop_front();
            if (x-l != dq[a[l]].front()-x){
                bad[a[l]]--;
                if (!bad[a[l]]) good++;
            }
            dq[a[l]].push_front(x);
            l++;
        }
        while (l > L){
            l--;
            if (dq[a[l]].empty()){
                dq[a[l]].push_front(l);
                dif++;
                good++;
                continue;
            }
            if (dq[a[l]].size() == 1){
                dq[a[l]].push_front(l);
                continue;
            }
            int x = dq[a[l]].front();
            dq[a[l]].pop_front();
            if (x-l != dq[a[l]].front()-x){
                bad[a[l]]++;
                if (bad[a[l]] == 1) good--;
            }
            dq[a[l]].push_front(x);
            dq[a[l]].push_front(l);
        }
        while (r > R){
            r--;
            dq[a[r]].pop_back();
            if (dq[a[r]].empty()){
                dif--;
                good--;
                continue;
            }
            if (dq[a[r]].size() == 1){
                continue;
            }
            int x = dq[a[r]].back();
            dq[a[r]].pop_back();
            if (r-x != x-dq[a[r]].back()){
                bad[a[r]]--;
                if (!bad[a[r]]) good++;
            }
            dq[a[r]].pb(x);
        }
        ans[Q[i].Y] = dif+(good == 0);
    }
    rep(i,0,q) cout << ans[i] << endl;
}