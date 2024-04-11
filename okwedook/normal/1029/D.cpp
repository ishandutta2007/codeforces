#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;

char mem[255 * 1000 * 1000];
int mpos = 0;
void* operator new(size_t n) { return mem + (mpos += n) - n; }
void operator delete(void*) {} 
 
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
#define ll int
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
 
const ll N = 12;
ll n, k;
vector<ll> arr;
vector<ll> mylog;
map<ll, ll> cnt[N];
long long ans = 0;

void mul2(ll &x) {
    x <<= 1;
    if (x >= k) x -= k;
}

ll sum(ll &a, ll b) {
    a += b;
    if (a >= k) a -= k;
}

void solve() {
    for (int i = 0; i < N; ++i) cnt[i].clear();
    for (int i = 0; i < n; ++i) {
        int ind = k - arr[i];
        for (int j = 0; j < N; ++j) {
            if (cnt[j].count(ind))
                ans += cnt[j][ind];
            mul2(ind);
            ll res = ind;
            mul2(ind);
            mul2(ind);
            sum(ind, res);
        }
        ++cnt[mylog[i]][arr[i] == k ? 0 : arr[i]];
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> k;
    arr = mylog = vector<ll>(n);
    for (auto &i : arr) cin >> i;
    for (int i = 0; i < n; ++i) mylog[i] = sz(to_string(arr[i]));
    for (auto &i : arr) i = (i - 1) % k + 1;
    solve();
    reverse(arr);
    reverse(mylog);
    solve();
    cout << ans;
    return 0;
}