#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define fi first
#define se second
#define int long long
#define pii pair<int, int>
#define rev(s) s, std::vector<s>, greater<s>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
#ifndef print
#define print(...)
#endif
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int t[100005];
int ft[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i) cin >> t[i];
	oset seat;
	for (int i = 0; i < n; ++i) seat.insert(i);
	priority_queue<rev(int)> waitseat;
	queue<int> waitline;
	priority_queue<rev(pii)> notwait;
	for (int i = 0; i < n; ++i)
		notwait.push({t[i], i});
	int tim = 0;
	set<int> mom;
	int pp = -1;
	while (!notwait.empty() || !waitline.empty() || !waitseat.empty()) {
		bool ok = 0;
		while (!notwait.empty() && tim > notwait.top().fi) {
			ok = 1;
			int tt = notwait.top().fi;
			while (!notwait.empty() && notwait.top().fi == tt) {
				waitseat.push(notwait.top().se);
				notwait.pop();
			}
			if (!waitseat.empty() && seat.order_of_key(waitseat.top()) == waitseat.top()) {
				if (mom.find(tt) == mom.end()) {
					mom.insert(tt);
					seat.erase(waitseat.top());
					waitline.push(waitseat.top());
					waitseat.pop();
				}
			}
		}
		if (pp != -1) {
			seat.insert(pp);
		}
		while (!notwait.empty() && tim >= notwait.top().fi) {
			// ok = 1;
			// int tt = notwait.top().fi;
			// while (!notwait.empty() && notwait.top().fi == tt) {
			waitseat.push(notwait.top().se);
			notwait.pop();
		}
		// if (!ok)
		if (!waitseat.empty() && seat.order_of_key(waitseat.top()) == waitseat.top()) {
			if (mom.find(tim) == mom.end()) {
				mom.insert(tim);
				seat.erase(waitseat.top());
				waitline.push(waitseat.top());
				waitseat.pop();
			}
		}
		if (waitline.empty()) {
			tim = notwait.top().fi;
			pp = -1;
		} else {
			tim += p;
			ft[waitline.front()] = tim;
			// seat.insert(waitline.front());
			pp = waitline.front();
			waitline.pop();
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ft[i] << " ";
}