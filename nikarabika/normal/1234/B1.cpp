//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> s;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (s.find(x) != s.end())
			continue;
		if (sz(s) < k) {
			q.push_front(x);
			s.insert(x);
		}
		else {
			s.erase(q.back());
			q.pop_back();
			q.push_front(x);
			s.insert(x);
		}
	}
	cout << sz(q) << '\n';
	for (int i = 0; i < sz(q); i++)
		cout << q[i] << ' ';
	cout << '\n';
	return 0;
}