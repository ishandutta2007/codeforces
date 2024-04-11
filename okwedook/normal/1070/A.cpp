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
 
const int N = 2000;

signed main() {
    FAST; FIXED; RANDOM;
    ll d, s;
    cin >> d >> s;
    vector<vector<pair<pii, int>>> past(d, vector<pair<pii, int>>(s + 1));
    vector<vector<bool>> used(d, vector<bool>(s + 1));
    deque<pair<pll, ll>> bfs;
    for (int i = 1; i < 10 && i <= s; ++i) {
        past[i % d][i] = mp(mp(-1, -1), i);
        bfs.pb(mp(mp(i % d, i), i));
        used[i % d][i] = true;
    }
    while (!used[0][s] && sz(bfs)) {
        auto front = bfs.front();
        bfs.popf();
        for (int i = 0; i < 10; ++i) {
            int newind = (front.f.f * 10 + i) % d;
            int newsum = front.f.s + i;
            if (newsum <= s && !used[newind][newsum]) {
                used[newind][newsum] = true;
                past[newind][newsum] = mp(front.f, i);
                bfs.pb(mp(mp(newind, newsum), front.s * 10 + i));
            }
        }
    }
    if (!used[0][s]) {
        cout << -1;
        return 0;
    }
    string ans = "";
    pll curr = mp(0, s);
    while (curr.f >= 0) {
        ans += char('0' + past[curr.f][curr.s].s);
        curr = past[curr.f][curr.s].f;
    }
    reverse(ans);
    cout << ans;
    return 0;
}