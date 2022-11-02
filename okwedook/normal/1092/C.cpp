#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
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

bool cmp(const string &a, const string &b) {
    return sz(a) < sz(b);
}

vector<string> arr;
vector<char> ans;
vector<bool> preftaken;

void check(int p, int s) {
    if (arr[p].substr(1, sz(arr[p]) - 1) != arr[s].substr(0, sz(arr[s]) - 1)) return;
    preftaken = vector<bool> (sz(arr) + 100);
    ans = vector<char>(sz(arr));
    for (int i = 0; i < sz(arr); ++i) {
        if (!preftaken[sz(arr[i])] && arr[p].substr(0, sz(arr[i])) == arr[i]) {
            ans[i] = 'P';
            preftaken[sz(arr[i])] = true;
        } else if (arr[s].substr(sz(arr[s]) - sz(arr[i]), sz(arr[i])) == arr[i]) ans[i] = 'S';
        else return;
    }
    for (auto i : ans) cout << i;
    exit(0);
}

signed main() {
    FAST; FIXED; RANDOM;
    int ind1 = 0, ind2 = 0;
    int n;
    cin >> n;
    arr = vector<string> (2 * n - 2);
    for (auto &i : arr) cin >> i;
    for (int i = 0; i < sz(arr); ++i)
        if (sz(arr[i]) == n - 1) ind2 = i;
    for (int i = sz(arr) - 1; i >= 0; --i)
        if (sz(arr[i]) == n - 1) ind1 = i;
    check(ind1, ind2);
    check(ind2, ind1);
    return 0;
}