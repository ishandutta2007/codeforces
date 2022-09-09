#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct arr {
	vector <int> a;
};

int n, k;
int a[1000];
int sum = 0;
arr d[100];
bool used[100];
//
int dfs(int n) {
	used[n] = true;
	int s1 = 1;
	for (int i = 0; i < d[n].a.size(); i++) {
		if (!used[d[n].a[i]]) {
			s1 = max(s1, 1+dfs(d[n].a[i]));
		}
	}
	used[n] = false;
	return s1;
}
//

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> n;
	int sum = 1;
	//
	for (int i = 0; i < n; i++) {
		cin >> k;
		int sum1 = 0;
		for (int j = 0; j < 100; j++) {
			d[j].a.clear();
		}
		for (int j = 0; j < k-1; j++) {
			int x, y;
			cin >> x >> y;
			d[x-1].a.push_back(y-1);
			d[y-1].a.push_back(x-1);
		}
		for (int j = 0; j < k; j++) {
			for (int i1 = 0; i1 < k; i1++) {
				used[i] = false;
			}
			sum1 = max(sum1, dfs(j));
		}
		sum += sum1-1;
	}
	//
	if (n == 0) sum = 0;
	cout << sum-1 << endl;
	//
	return 0;
}