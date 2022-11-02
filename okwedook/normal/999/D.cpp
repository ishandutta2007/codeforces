#pragma GCC optimize("O3","unroll-loops")
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
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<class T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<class T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<ll> cnt, mynext;
ll block;

ll dist(ll a, ll b, ll m) {
    if (a > b) return b + m - a;
    else return b - a;
}

ll find_next(ll a) {
    if (cnt[a] < block) return a;
    return mynext[a] = find_next(mynext[a]);
}

int main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> sarr(n);
    for (int i = 0; i < n; ++i) 
        sarr[i] = arr[i] / m, arr[i] -= sarr[i] * m;
    vector<bool> free(n);
    cnt = vector<ll> (m);
    for (auto i : arr) cnt[i]++;
    block = n / m;
    for (int i = 0; i < n; ++i)
        if (cnt[arr[i]] > block) --cnt[arr[i]], free[i] = true;
    mynext = vector<ll> (m);
    for (int i = 0; i < m; ++i) mynext[i] = (i + 1) % m;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        if (free[i]) {
            ll curr = find_next(arr[i]);
            ans += dist(arr[i], curr, m);
            if (arr[i] > curr) ++sarr[i];
            arr[i] = curr;
            ++cnt[curr];
        }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) cout << (sarr[i] * m + arr[i]) << ' ';
    return 0;
}