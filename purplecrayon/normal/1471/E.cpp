#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, cnt_qry=0;
ll k;

ll qry(int i){
    assert(i >= 0 && i < n);
    cnt_qry++;
    cout << "? " << (i+1) << endl;
    int x; cin >> x;
    return x;
}
int r(int l, int r){ 
    return uniform_int_distribution<int>(l, r)(rng);
}
void solve(){
    cin >> n >> k;
    int c;
    ll v;
    do {
        c = r(0, n-1);
        v = qry(c);
    } while (v == k);

    int offset=(v<k?1:-1);
    c=(c+n+offset)%n;
    while (qry(c) != k) c=(c+n+offset)%n;
    cout << "! " << (c+1) << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}