<<<<<<< HEAD
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
const int MAXN = 5e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n[3];
    for (auto& it : n) cin >> it;
    vector<ll> a[3];
    ll mn[3]={}, sm = 0;
    for (int i = 0; i < 3; i++){
        a[i].assign(n[i], 0);
        for (auto& it : a[i]) cin >> it;
        mn[i] = *min_element(a[i].begin(), a[i].end());
        sm += accumulate(a[i].begin(), a[i].end(), 0ll);
    }
    ll ans=sm;
    for (auto& it : mn) ans -= 2*it;
    ans += 2*(*max_element(mn, mn+3));
    for (int i = 0; i < 3; i++) ans = max(ans, sm-2*accumulate(a[i].begin(), a[i].end(), 0ll));
    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve(); 
=======
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
vector<vector<int>> a(3, vector<int>());
vector<int> n(3, 0);

int calc() {
    int ans = 0, m1 = a[1][0], m2 = a[2][0], s1 = 0, s2 = 0;
    for (int i : a[0]) ans += i;
    for (int i = 1; i < n[1]; i++) s1 += a[1][i];
    for (int i = 1; i < n[2]; i++) s2 += a[2][i];

    ans += max({s2 - m1 + s1 - m2, m2 + s2 - m1 - s1, m1 + s1 - m2 - s2});
    return ans;
}

void solveTestCase() {
    cin >> n[0] >> n[1] >> n[2];
    a[0].resize(n[0]);
    a[1].resize(n[1]);
    a[2].resize(n[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    int ans = -1e18;
    ans = max(ans, calc());

    swap(a[0], a[1]), swap(n[0], n[1]);
    ans = max(ans, calc());

    swap(a[0], a[2]), swap(n[0], n[2]);
    ans = max(ans, calc());

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solveTestCase();
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
}