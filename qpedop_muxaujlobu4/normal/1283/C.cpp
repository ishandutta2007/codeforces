#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
bool give[200001];
bool have[200001];
int pred[200001];
int main() {
	set<int>HAVE;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		give[i] = have[i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> pred[i];
		if (pred[i]) {
			give[i] = true;
			have[pred[i]] = true;
		}
	}
	int j;
	for (j = 1; j <= n; ++j) {
		if (!have[j])HAVE.insert(j);
	}
	auto it = HAVE.begin();
	for (int i = 1; i <= n; ++i) {
		if (!have[i] && !give[i]) {
			if (HAVE.begin() == HAVE.end())break;
			if (i == *it) {
				++it;
				if (it == HAVE.end())it = HAVE.begin();
			}
			give[i] = true;
			have[*it] = true;
			pred[i] = *it;
			HAVE.erase(it);
			it = HAVE.begin();
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!give[i]) {
			if (HAVE.begin() == HAVE.end())break;
			if (i == *it) {
				++it;
				if (it == HAVE.end())it = HAVE.begin();
			}
			give[i] = true;
			have[*it] = true;
			pred[i] = *it;
			HAVE.erase(it);
			it = HAVE.begin();
		}
	}
	for (int i = 1; i <= n; ++i)cout << pred[i] << " ";
	return 0;
}