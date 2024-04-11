#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5;
vector<ll> ve,dp[N][20];
vector<int> tajz[N];
int sz;
void f(ll n,int k){
    if (sz == N)
        return;
    if (!k){
        ve.pb(n);
        sz++;
        return;
    }
    if (n == 1){
        ve.pb(1);
        sz++;
        return;
    }
    if (k+sz >= N){
        rep(i,sz,N)
            ve.pb(1);
        sz = N;
        return;
    }
    if (n < N){
        if (tajz[n].size() == 2){
            rep(i,0,k) ve.pb(1);
            ve.pb(n);
            sz += k+1;
            return;
        }
        for (int u : tajz[n]){
            f(u,k-1);
            if (sz == N) break;
        }
        return;
    }
    int sq = sqrt(n)+1;
    vector<ll> ve2;
    ve2.reserve(100);
    rep(i,1,sq){
        if (n%i == 0){
            if (i < n/i) ve2.pb(n/i),ve2.pb(i);
            else if (i == n/i) ve2.pb(i);
        }
    }
    if (ve2.size() == 2){
        rep(i,0,k) ve.pb(1);
        ve.pb(n);
        sz += k+1;
        return;
    }
    sort(ve2.begin(),ve2.end());
    if (ve2.size() == 3){
        while (k){
            if (sz+k >= N){
                rep(i,sz,N) ve.pb(1);
                sz = N;
                return;
            }
            rep(i,0,k) ve.pb(1);
            ve.pb(ve2[1]);
            sz += k+1;
            k--;
        }
        if (sz < N) ve.pb(n);
        return;
    }
    if (ve2.size() == 4){
        while (k){
            if (sz+k >= N){
                rep(i,sz,N) ve.pb(1);
                sz = N;
                return;
            }
            rep(i,0,k) ve.pb(1);
            ve.pb(ve2[1]);
            sz += k+1;
            if (sz + k > N){
                rep(i,sz,N) ve.pb(1);
                sz = N;
                return;
            }
            rep(i,1,k) ve.pb(1);
            ve.pb(ve2[2]);
            sz += k;
            if (sz >= N) return;
            k--;
        }
        ve.pb(n);
        sz++;
        return;
    }
    for(ll u : ve2){
        f(u,k-1);
        if (sz == N) return;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin >> n >> k;
    if (n == 1){
        cout << 1;
        return 0;
    }
    if (k >= N){
        rep(i,0,N) cout << 1 << ' ';
        return 0;
    }
    rep(i,1,N)
        for (int j = 1; j*i < N; j++)
            tajz[j*i].pb(i);
    f(n,k);
    //cout << "cout << ";
    for(ll u : ve) cout << u << ' ';
}