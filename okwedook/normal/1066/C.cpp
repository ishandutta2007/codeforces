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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

const ll N = 1000000; 
ll fenv[N];

void add(int r) {
    for (; r < N; r |= r + 1) ++fenv[r];
}

ll get(int r) {
    ll ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ans += fenv[r];
    return ans;
}

ll get(int l, int r) {
    return get(r) - get(l - 1);
}

signed main() {
    FAST; FIXED; RANDOM;
    int ptrl = 0, ptrr = 1;
    map<int, int> st;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char mode;
        cin >> mode;
        int id;
        cin >> id;
        if (mode == 'L') {
            st[id] = ptrl;
            ptrl--;
        } else if (mode == 'R') {
            st[id] = ptrr;
            ptrr++;
        } else {
            cout << min(st[id] - ptrl - 1, ptrr - st[id] - 1) << '\n';
        }
    }
    return 0;
}