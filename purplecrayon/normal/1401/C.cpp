#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n), sorted;
    int mn = INF;
    for (int i = 0; i < n; i++){
        cin >> a[i].first; sorted.push_back({a[i].first, i});
        mn = min(mn, a[i].first);
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++){
        a[sorted[i].second].second = i;
    }
    for (int i = 0; i < n; i++){
        if (i == a[i].second) continue;
        if (a[i].first%mn != 0 && a[i].second != i) { cout << no; return; }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}