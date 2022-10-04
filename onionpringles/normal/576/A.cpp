#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int isprime(int m) {
	for (int i = 2; i*i <= m; i++) {
		if (m%i == 0) return 0;
	}
	return 1;
}

vector<int> ans;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		if (isprime(i)) {
			int j = i;
			while (j <= n) {
				ans.push_back(j);
				j *= i;
			}
		}
	}
	printf("%d\n", ans.size());
	for (auto &x : ans)printf("%d ", x);

	return 0;
}