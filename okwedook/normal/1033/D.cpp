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

vector<int> primes;

ll two(ll n) {
    ll l = 0, r = 1414213563;
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (m * m > n) r = m;
        else l = m;
    }
    return l;
}

ll three(ll n) {
    ll l = 0, r = 1259922;
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (m * m * m > n) r = m;
        else l = m;
    }
    return l;
}

ll four(ll n) {
    ll l = 0, r = 37607;
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (m * m * m * m > n) r = m;
        else l = m;
    }
    return l;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    set<ll> poss;
    hashmap<ll, ll> st;
    for (auto &i : arr) {
        ll x = four(i);
        if (x * x * x * x == i) {
            poss.insert(x);
            st[x] += 4;
            i = 1;
            continue;
        }
        x = three(i);
        if (x * x * x == i) {
            poss.insert(x);
            st[x] += 3;
            i = 1;
            continue;
        }
        x = two(i);
        if (x * x == i) {
            poss.insert(x);
            st[x] += 2;
            i = 1;
            continue;
        }
    }
    for (auto &i : arr)
        for (auto &j : arr) {
            ll g = __gcd(i, j);
            if (g > 1 && g < min(i, j))
                poss.insert(g);
        }
    for (auto j : poss)
        for (auto &i : arr) 
            while (i % j == 0) {
                i /= j;
                st[j]++, st[i]++;
                i = 1;
            }
    hashmap<ll, ll> been;
    int cnt = 0;
    for (auto i : arr) {
        if (i > 1) {
            if (i <= 2e9) {
                bool flag = false;
                for (ll j = 2; j * j < i; ++j)
                    if (i % j == 0) {
                        flag = true;
                        st[j]++, st[i / j]++;
                    }
                if (!flag) st[i]++;
            } else {
                if (!been.count(i)) been[i] = cnt++;
                st[-2 * been[i]]++;
                st[-2 * been[i] - 1]++;
            }
        }
    }
    ll ans = 1;
    for (auto i : st)
        ans = (ans * (i.s + 1)) % 998244353;
    cout << ans;
    return 0;
}