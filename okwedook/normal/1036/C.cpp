#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }

string s(18, '0');
set<ll> st;
vector<ll> arr;

ll get(ll x) {
    ll l = 0, r = sz(arr);
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (arr[m] <= x) l = m;
        else r = m;
    }
    return l;
}

void ins() {
    ll ans = 0;
    for (auto i : s)
        ans = ans * 10 + (i - '0');
    st.insert(ans);
}

signed main() {
    FAST; FIXED; RANDOM;
    st.insert(1000000000000000000ll);
    for (int a0 = 0; a0 < 18; ++a0) {
        for (int b0 = 0; b0 < 10; ++b0) {
            s[a0] = '0' + b0;
            for (int a1 = a0 + 1; a1 < 18; ++a1)
                for (int b1 = 0; b1 < 10; ++b1) {
                    s[a1] = '0' + b1;
                    for (int a2 = a1 + 1; a2 < 18; ++a2)
                        for (int b2 = 0; b2 < 10; ++b2) {
                            s[a2] = '0' + b2;
                            ins();
                            s[a2] = '0';
                        }
                    s[a1] = '0';
                }
            s[a0] = '0';
        }
    }
    for (auto i : st) arr.pb(i);
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll left, right;
        cin >> left >> right;
        cout << get(right) - get(left - 1) << '\n'; 
    }
    return 0;
}