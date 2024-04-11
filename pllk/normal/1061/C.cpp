#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define M 1000000007

int n;
int a[101010];
vector<int> v[1222333];
vector<int> w[101010];
ll t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	vector<pair<int,int>> u1, u2;
	u1.push_back({0,1});
	for (int i = 1; i <= 1000000; i++) {
		if (u1.size() == 0) break;
		u2.clear();
		vector<int> u;
		for (int j = i; j <= 1000000; j += i) {
			for (auto x : v[j]) {
				u.push_back(x);
			}
		}
		sort(u.begin(),u.end());
		int k = 0;
		ll s = 0;
		for (auto x : u) {
			while (k < u1.size() && u1[k].first < x) {
				s += u1[k].second;
				s %= M;
				k++;
			}
			t += s;
			t %= M;
			u2.push_back({x,s});
		}
		u1 = u2;
	}
	cout << t << "\n";
}