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
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

ll ask(ll a, ll b, ll c) {
	cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
	ll ans;
	cin >> ans;
	return ans;
}

ll getsum(ll a, ll b, ll c, ll d) {
	vector<ll> arr(4);
	arr[0] = ask(a, b, c);
	arr[1] = ask(a, b, d);
	arr[2] = ask(a, c, d);
	arr[3] = ask(b, c, d);
	sort(arr);
	return arr[0] + arr[3];
}

//(a + c) + (a + d) + (a + d) + (b + d)

int main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    ll a = getsum(0, 1, 2, 3);
    ll b = getsum(0, 1, 2, 4);
    ll c = getsum(0, 1, 3, 4);
    ll d = getsum(0, 2, 3, 4);
    ll e = getsum(1, 2, 3, 4);
    vector<ll> arr(n);
    ll sum5 = (a + b + c + d + e) / 4;
    arr[4] = sum5 - a;
    arr[3] = sum5 - b;
    arr[2] = sum5 - c;
    arr[1] = sum5 - d;
    arr[0] = sum5 - e;
    for (int i = 5; i < n; ++i) {
    	ll a = getsum(0, 1, 2, i);
    	arr[i] = a - arr[0] - arr[1] - arr[2];
    }
    cout << "! ";
    for (auto i : arr) cout << i << ' '; 
    return 0;
}