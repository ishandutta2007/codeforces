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

#define ll int

int main() {
    FAST; FIXED; RANDOM;
    ll n, y;
    cin >> n >> y;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    cin >> n >> y;
    vector<ll> brr(n);
    for (auto &i : brr) cin >> i;
    ll ans = 2, curr = 1;
    hashmap<ll, ll> st1, st2;
    while (curr <= 1 << 28) {
        st1.clear();
        st2.clear();
        for (auto i : arr) st1[i % (2 * curr)]++;
        for (auto i : brr) st2[(i + curr) % (2 * curr)]++;
        for (auto i : st1) checkmax(ans, i.s + st2[i.f]);
        for (auto i : st2) checkmax(ans, i.s + st1[i.f]);
        curr *= 2;
    }
    cout << ans;
    return 0;
}