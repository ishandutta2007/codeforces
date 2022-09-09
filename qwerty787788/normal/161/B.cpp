#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct pr {
	int id;
	long long cost;
};

int n, k;
vector <pr> t;
vector <pr> p;
vector <int> a[1001];
int cost[1001], type[1001];
//
bool cmp(pr p1, pr p2) {
	if (p1.cost > p2.cost) return true;
	return false;
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cost[i + 1] = x;
		type[i + 1] = y;
		if (y == 1) {
			pr p1;
			p1.id = i + 1;
			p1.cost = x;
			t.push_back(p1);
		} else {
			pr p1;
			p1.id = i + 1;
			p1.cost = x;
			p.push_back(p1);
		}
	}
	sort(t.begin(), t.end(), cmp);
	//
	int free = 0;
	while (t.size() > free && k > free) {
		a[free].push_back(t[free].id);
		free++;
	}
	if (free < k) {
		int i = 0;
		while (free < k) {
			a[free].push_back(p[i].id);
			free++;
			i++;
		}
		for (int j = i; j < p.size(); j++)
			a[k - 1].push_back(p[j].id);
	} else {
		for (int i = free; i < t.size(); i++)
			a[k - 1].push_back(t[i].id);
		for (int j = 0; j < p.size(); j++)
			a[k - 1].push_back(p[j].id);
	}
	double ans = 0;
	for (int i = 0; i < k; i++) {
		bool is_t = false;
		double min_ = 1e9;
		for (int j = 0; j < a[i].size(); j++) {
			if (type[a[i][j]] == 1) is_t = 1;
			if (cost[a[i][j]] < min_) min_ = cost[a[i][j]];
			ans += cost[a[i][j]];
		}
		if (is_t) ans -= min_/2;
	}
	printf("%.1llf\n", ans);
	for (int i = 0; i < k; i++) {
		cout << a[i].size() << " ";
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}