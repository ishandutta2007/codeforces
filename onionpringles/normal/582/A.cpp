#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

multiset<int> ms;
vector<int> ans;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n*n; i++) {
		int x;
		scanf("%d", &x);
		ms.insert(-x);
	}
	while (!ms.empty()) {
		auto it = ms.begin();
		int y = -(*it);
		ms.erase(it);
		for (auto &x : ans) {
			int g = gcd(x, y);
			auto it2 = ms.find(-g);
			ms.erase(it2);
			it2 = ms.find(-g);
			ms.erase(it2);
		}
		ans.push_back(y);
	}
	for (auto &x : ans) printf("%d ", x);

	return 0;
}