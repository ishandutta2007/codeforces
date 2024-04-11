#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

vector<int> hidden{1, 32, 1, 2, 4, 5};

int cnt_query = 0;

map<pair<int, int>, ll> mpa;
ll qry_and(int i, int j) {
    if (i > j) swap(i, j);
    if (mpa.count({i, j})) return mpa[{i, j}];
    cnt_query++;
#ifdef LOCAL
    return mpa[{i, j}] = hidden[i]&hidden[j];
#endif

    cout << "and " << i+1 << ' ' << j+1 << endl;
    ll x; cin >> x;
    return mpa[{i, j}] = x;
}
map<pair<int, int>, ll> mpb;
ll qry_or(int i, int j) {
    if (i > j) swap(i, j);
    if (mpb.count({i, j})) return mpb[{i, j}];
    cnt_query++;
#ifdef LOCAL
    return mpb[{i, j}] = hidden[i]|hidden[j];
#endif

    cout << "or " << i+1 << ' ' << j+1 << endl;
    ll x; cin >> x;
    return mpb[{i, j}] = x;
}
ll qry_xor(int i, int j) {
    ll a = qry_and(i, j);
    ll b = qry_or(i, j);
    return a^b;
}
ll qry_plus(int i, int j) {
    return qry_xor(i, j) + 2*qry_and(i, j);
}
int n, k;

void solve(){
    cin >> n >> k;
   
    ll ab = qry_plus(0, 1), bc = qry_plus(1, 2), ac = qry_plus(0, 2);
    ll abc = (ab+bc+ac)/2;
    ll a = abc-bc, b = abc-ac, c = abc-ab;

    vector<ll> x(n);
    x[0] = a, x[1] = b, x[2] = c;
    for (int i = 3; i < n; i++) {
        x[i] = qry_xor(0, i)^x[0];
    }
    sort(x.begin(), x.end());
    assert(cnt_query <= 2*n);
    cout << "finish " << x[k-1] << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}