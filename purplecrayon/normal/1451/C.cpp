#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    ar<int, 26> ca, cb; ca.fill(0), cb.fill(0);
    for (auto c : a) ca[c-'a']++;
    for (auto c : b) cb[c-'a']++;
    ar<int, 26> diff; for (int i = 0; i < 26; i++) diff[i] = ca[i]-cb[i];
    for (int i = 25; i >= 0; i--) if (diff[i]) {
        if (diff[i] > 0){ cout << no; return; }
        if ((-diff[i])%k){ cout << no; return; }
        int left=-diff[i];
        for (int j = i-1; j >= 0 && left; j--) while (diff[j] >= k && left) left -= k, diff[j] -= k;
        if (left) { cout << no; return; }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}