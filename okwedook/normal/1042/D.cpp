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
#define inf 1e14 + 1
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

ll n, t, ans = 0;
vector<ll> arr;
vector<ll> t1, t2;

void solve(int from, int to, vector<ll> &pref, vector<ll> &suff) {
    if (to == from) return;
    if (to - from == 1) {
        suff = pref = { arr[from] };
        if (arr[from] < t) ++ans;
        return;
    }
    int mid = from + to >> 1;
    vector<ll> p1, s1, p2, s2;
    solve(from, mid, p1, s1);
    solve(mid, to, p2, s2);
    /*if (from == 0 && to == 4) {
        for (auto i : s1) cout << i << ' ';
        cout << '\n';
        for (auto i : p2) cout << i << ' ';
        cout << '\n' << '\n';
    }*/
    int ptr = sz(p2) - 1;
    for (int i = 0; i < sz(s1); ++i) {
        while (ptr >= 0 && s1[i] + p2[ptr] >= t) --ptr;
        if (ptr < 0) break;
        /*cout << from << ' ' << to << '\n';
        cout << i << ' ' << ptr << '\n' << '\n';*/
        ans += ptr + 1;
    }
    for (int i = from; i < to; ++i)
        pref.pb(arr[i]);
    for (int i = to - 1; i >= from; --i)
        suff.pb(arr[i]);
    for (int i = 1; i < sz(pref); ++i)
        pref[i] += pref[i - 1];
    for (int i = 1; i < sz(suff); ++i)
        suff[i] += suff[i - 1];
    sort(pref); sort(suff);
}

int main() {
    FAST; FIXED; RANDOM;
    cin >> n >> t;
    arr.resize(n);
    for (auto &i : arr) cin >> i;
    solve(0, n, t1, t2);
    cout << ans;
    return 0;
}