#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
typedef long long ll;
typedef double db;
using namespace std;

struct sofa {
	int x, y, index;
	sofa(int a = 0, int b = 0, int i = 0) : x(a), y(b), index(i) {};
};

bool cmpx(sofa &a, sofa &b) {
	return a.x < b.x;
}

bool cmpy(sofa &a, sofa &b) {
	return a.y < b.y;
}
#define ok cout << "A" << endl;
int main() {
	ios::sync_with_stdio(0);
	int n, a, x;
	vector<int> cnts(1000001, 0);
	set<pair<int, int>> counts;
	cin >> n >> a;
	for (int i = 1; i <= 1000000; i++)
		if (i != a)
			counts.insert({ 0, i });
	counts.insert({ 0, -1 });
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != a) {
			if (cnts[x] != -1) {
				counts.erase({ cnts[x], x });
				cnts[x]++;
				counts.insert({ cnts[x], x });
			}
		}
		else {
			counts.erase({ cnts[x], -1 });
			cnts[x]++;
			counts.insert({ cnts[x], -1 });
			while (counts.begin()->second != -1)
				cnts[counts.begin()->second] = -1, counts.erase(counts.begin());
		}
	}
	if (counts.size() < 2) {
		cout << -1 << endl;
		return 0;
	}
	set<pair<int, int>>::iterator it = counts.begin(); it++;
	cout << it->second << endl;
	return 0;
}