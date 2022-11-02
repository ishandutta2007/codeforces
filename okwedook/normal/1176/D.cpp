#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(235345)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 998244353
#define inf 3000000000000000007ll
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

const int mx = 2750132;
const int N = 2e5 + 10;
int primelink[N];
bool prime[mx];
int mxd[N];
int c[mx];

signed main() {
    FAST; FIXED; RANDOM;
    for (int i = 2; i < mx; ++i) prime[i] = true;
    for (int i = 2; i * i < mx; ++i)
        for (int j = i * i; j < mx; j += i)
            prime[j] = false;
    int cnt = 0;
    for (int i = 2; i < mx; ++i) {
        if (prime[i]) {
            ++cnt;
            if (prime[cnt]) 
                primelink[cnt] = i;
        }
    }
    for (int i = 2; i < N; ++i)
        for (int j = i + i; j < N; j += i)
            mxd[j] = i;
    int n;
    cin >> n;

    n *= 2;
    while (n--) {
        int a;
        cin >> a;
        c[a]++;
    }
    for (int i = 2e5; i >= 2; --i) {
        while (c[i]) {
            if (prime[i]) {
                if (c[primelink[i]]) {
                    cout << i << ' ';
                    --c[i];
                    --c[primelink[i]];
                } else break;
            } else if (c[mxd[i]]) {
                cout << i << ' ';
                --c[i];
                --c[mxd[i]];
            } else break;
        }
    }
    return 0;
}