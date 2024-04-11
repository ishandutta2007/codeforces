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

string tostr(int ind) {
	string ans = "a1";
	ans[1] += ind / 8;
	ans[0] += ind % 8;
	return ans;
}

int fromstr(string str) {
	return (str[1] - '1') * 8 + (str[0] - 'a');
}

bool check(pii a) {
	return a.f >= 0 && a.s < 8 && a.s >= 0 && a.f < 8;
}

pii topii(int ind) {
	return pii(ind % 8, ind / 8);
}

int frompii(pii a) {
	return a.s * 8 + a.f;
}

map<pii, pii> past;
map<pii, bool> used;
deque<pii> que;

void add(pii a, pii was) {
	if (check(a) && !used[a]) {
		used[a] = true;
		que.pb(a);
		past[a] = was;
	}
}

void bfs(pii a, pii b) {
	used.clear();
	past.clear();
	que.pb(a);
	used[a] = true;
	while (sz(que) > 0) {
		pii was = que.front();
		add({was.f + 1, was.s + 2}, was);
		add({was.f + 1, was.s - 2}, was);
		add({was.f - 1, was.s + 2}, was);
		add({was.f - 1, was.s - 2}, was);

		add({was.f + 2, was.s + 1}, was);
		add({was.f + 2, was.s - 1}, was);
		add({was.f - 2, was.s + 1}, was);
		add({was.f - 2, was.s - 1}, was);
		que.popf();
	}
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	arr[i] = topii(fromstr(s));
    }
    vector<pair<pii, pii>> ans;
    for (int i = 0; i < n; ++i) {
    	bool flag = false;
    	for (auto j : arr)
    		if (frompii(j) == i) {
    			flag = true;
    			break;
    		}
    	if (flag) continue;
    	for (auto &j : arr)
    		if (frompii(j) >= n) {
    			pii curr = topii(i);
    			bfs(j, curr);
    			vector<pii> toadd;
    			pii start = j;
    			while (start == j) {
    				toadd.pb(curr);
    				curr = past[curr];
   					for (auto &t : arr)
   						if (t == curr) {
   							while (sz(toadd) > 0) {
   								ans.pb({t, toadd.back()});
   								t = toadd.back();
   								toadd.popb();
   							}
   							break;
   						}
    			}
    			break;
    		}
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) {
    	cout << tostr(frompii(i.f)) << '-' << tostr(frompii(i.s)) << '\n';
    }
    return 0;
}