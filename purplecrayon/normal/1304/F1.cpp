#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void fsc(ll &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1ll)+(x<<3ll)+c-48ll;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
} 

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 50+10, MAXM = 2e4+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct Vertex {
    int left, right;
    ll mx = -INF;
    Vertex *left_child = nullptr, *right_child = nullptr;
    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }
    void extend() {
        if (!left_child && left < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t+1, right);
        }
    }
    void upd(int k, ll x) {
        extend();
        if (left_child) {
            if (k <= left_child->right) left_child->upd(k, x);
            else right_child->upd(k, x);
            mx = max(right_child->mx, left_child->mx);
        } else mx = x;
    }
    ll qry(int lq, int rq) {
        if (lq <= left && right <= rq) return mx;
        if (max(left, lq) > min(right, rq)) return -INF;
        extend();
        return max(left_child->qry(lq, rq), right_child->qry(lq, rq));
    }
    void pr(){
        extend();
        cout << "PR: " << left << ' ' << right << ' ' << mx << '\n';
        if (left_child){
            left_child->pr(); right_child->pr();
        }
    }
};

Vertex* st[4];

int n, m, K;
ll a[MAXN][MAXM], ps[MAXN][MAXM], dp[MAXN][MAXM];

void solve(){
    read(n, m, K); memset(ps, 0, sizeof(ps));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) read(a[i][j]), ps[i][j+1] = a[i][j]+ps[i][j];
    memset(dp, 0, sizeof(dp));
    auto s = [&](int i, int l, int r) -> ll {
        return ps[i][r+1]-ps[i][l];
    };
    for (int j = 0; j+K <= m; j++) dp[0][j] = s(0, j, j+K-1);
    /*
    for (int i = 1; i < n; i++) for (int j = 0; j+K <= m; j++){
        ll cc=s(i, j, j+K-1);
        for (int k = 0; k <= j-K; k++){
            dp[i][j] = max(dp[i][j], dp[i-1][k]+cc+ps[i][k+K]-ps[i][k]);
        }
        for (int k = max(j-K+1, 0); k <= j; k++) {  //overlap from j -> k+K-1
            dp[i][j] = max(dp[i][j], dp[i-1][k]+cc-ps[i][k]+ps[i][j]);
        }
        for (int k = j+1; k <= min(j+K-1, m-K); k++){ //overlap from k -> j+K-1
            dp[i][j] = max(dp[i][j], dp[i-1][k]+cc+ps[i][k+K]-ps[i][j+K]);
        }
        for (int k = j+K; k <= m-K; k++){
            dp[i][j] = max(dp[i][j], dp[i-1][k]+cc+ps[i][k+K]-ps[i][k]);
        }
    }*/
    for (int i = 1; i < n; i++){
        for (int s=0; s<4; s++) st[s] = new Vertex(0, 2*m);
        for (int k = 0; k+K <= m; k++){
            st[0]->upd(k, dp[i-1][k]+ps[i][k+K]-ps[i][k]); //cout << "0: " << dp[i-1][k]+ps[i][k+K]-ps[i][k] << '\n';
            st[1]->upd(k, dp[i-1][k]-ps[i][k]); //cout << "1: " << dp[i-1][k]-ps[i][k] << '\n';
            st[2]->upd(k, dp[i-1][k]+ps[i][k+K]); //cout << "2: " << dp[i-1][k]+ps[i][k+K] << '\n';
            st[3]->upd(k, dp[i-1][k]+ps[i][k+K]-ps[i][k]); //cout << "3: " << dp[i-1][k]+ps[i][k+K]-ps[i][k] << '\n';
        }
        for (int j = 0; j+K <= m; j++){
            ll cc=s(i, j, j+K-1);
            dp[i][j] = max(dp[i][j], st[0]->qry(0, j-K)+cc); //cout << "QRY 0: " << st[0]->qry(0, j-K)+cc << '\n';
            dp[i][j] = max(dp[i][j], st[1]->qry(max(j-K+1, 0), j)+cc+ps[i][j]); //cout << "QRY 1: " << st[1]->qry(max(j-K+1, 0), j)+cc+ps[i][j] << '\n';
            dp[i][j] = max(dp[i][j], st[2]->qry(j+1, min(j+K-1, m-K))+cc-ps[i][j+K]); //cout << "QRY 2: " << st[2]->qry(j+1, min(j+K-1, m-K))+cc-ps[i][j+K] << '\n';
            dp[i][j] = max(dp[i][j], st[3]->qry(j+K, m-K)+cc);// cout << "QRY 3: " << st[3]->qry(j+K, m-K)+cc << '\n';
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j+K <= m; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    ll ans=0;
    for (int j = 0; j+K <= m; j++) ans = max(ans, dp[n-1][j]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t;
    while (t--) solve();
}