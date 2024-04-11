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

vector<bool> used;
vector<int> mind;

bool check(int n) {
    while (n > 1) {
        if (used[mind[n]]) return false;
        n /= mind[n];
    }
    return true;
}

void add(int n) {
    while (n > 1) {
        used[mind[n]] = true;
        n /= mind[n];
    }
}

int main() {
    FAST; FIXED; RANDOM;
    int N = 1.5e6;
    mind = vector<int> (N);
    for (int i = 2; i < N; ++i) 
        if (mind[i] == 0) {
            mind[i] = i;
            if (N / i >= i)
                for (int j = i * i; j < N; j += i)
                    if (mind[j] == 0) mind[j] = i;
        }
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    used = vector<bool> (N);
    bool flag = false, change = false;
    int past;
    for (auto &i : arr) {
        if (flag) i = past + 1;
        while (!check(i)) { 
            ++i;
            ++past;
            flag = true;
        }
        add(i);
        if (flag && !change) change = true, past = 1;
    }
    for (auto i : arr) cout << i << ' ';
    return 0;
}