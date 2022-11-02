#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(9)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }

int main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<pll> arr(n - 1);
    for (auto &i : arr) cin >> i.f >> i.s;
    map<ll, ll> st;
    vector<ll> brr;
    for (auto &i : arr) {
        if (i.f != n && i.s != n || i.f == i.s) {
            cout << "NO";
            return 0;
        }
        st[-min(i.f, i.s)]++;
        brr.pb(min(i.f, i.s));
    }
    sort(brr);
    vector<ll> ans(n);
    ll mn = n - 1;
    ans[mn] = n;
    bool flag = true;
    for (auto i : st) {
        mn -= i.s;
        ans[mn] = -i.f;
    }
    vector<bool> used(n + 1);
    for (auto i : ans) used[i] = true;
    vector<ll> temp;
    for (int i = 1; i <= n; ++i)
        if (!used[i]) 
            temp.pb(i);
    int ptr = 0;
    for (auto &i : ans)
        if (i == 0)
            i = temp[ptr++];
    vector<ll> check;
    ll curr = 0;
    for (int j = 0; j < n - 1; ++j) {
        checkmax(curr, ans[j]);
        check.pb(curr);
    }
    sort(check);
    if (check == brr) {
        cout << "YES\n";
        for (int i = 1; i < n; ++i)
            cout << ans[i - 1] << ' ' << ans[i] << '\n';
    } else cout << "NO";
    return 0;
}