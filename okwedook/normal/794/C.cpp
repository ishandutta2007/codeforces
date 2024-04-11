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
#define mod 10000000007
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

signed main() {
    FAST; FIXED; RANDOM;
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1); rsort(s2);
    int n = sz(s1);
    deque<char> deq1, deq2;
    for (int i = 0; i < n / 2; ++i) deq1.pb(s1[i]);
    for (int i = 0; i < n / 2; ++i) deq2.pb(s2[i]);
    if (n & 1) deq1.pb(s1[n / 2]);
    string ans = s1;
    bool flag = true;
    int ptra = 0, ptrb = n - 1;
    while (sz(deq1) || sz(deq2)) {
        /*for (auto i : deq1) cout << i;
        cout << '\n';
        for (auto i : deq2) cout << i;
        cout << endl;*/
        if (flag) {
            if (sz(deq2) == 0 || deq1.front() >= deq2.front()) ans[ptrb--] = deq1.back(), deq1.popb();
            else ans[ptra++] = deq1.front(), deq1.popf();
        } else {
            if (sz(deq1) == 0 || deq2.front() <= deq1.front()) ans[ptrb--] = deq2.back(), deq2.popb();
            else ans[ptra++] = deq2.front(), deq2.popf();
        }
        flag = !flag;
    }
    for (auto i : ans) cout << i;
    return 0;
}