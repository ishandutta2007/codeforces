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
#define s sec
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

ll n, k;
bool a[16];
int add[4];

ll read() {
    ll res = 0;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        res = res << 1 | a;
    }
    return res;
}

void some(int i) {
    int curr = 0;
    while (i > 0) add[curr++] += i & 1, i >>= 1;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        a[read()] = true;
    if (a[0]) {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i < 1 << 16; ++i) {
        bool flag = true;
        for (int j = 0; j < 16; ++j)
            if ((i >> j) & 1) flag = flag && a[j];
        if (!flag) continue;
        memset(add, 0, sizeof add);
        ll cnt = 0;
        for (int j = 0; j < 16; ++j)
            if ((i >> j) & 1) some(j), ++cnt;
        cnt = cnt / 2;
        flag = true;
        for (int j = 0; j < 4; ++j)
            if (add[j] > cnt) flag = false;
        if (flag) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0; 
}