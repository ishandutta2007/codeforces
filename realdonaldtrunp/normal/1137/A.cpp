#include"bits/stdc++.h"

using namespace std;

#define MAX 1002

int n;
int m;
int r[MAX][MAX];

int x[MAX][MAX];
int y[MAX][MAX];
int maxx[MAX];
int maxy[MAX];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &r[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			v.push_back(r[i][j]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int j = 0; j < m; j++) {
			x[i][j] = lower_bound(v.begin(), v.end(), r[i][j]) - v.begin()+1;
		}
		maxx[i] = v.size();
	}
	for (int j = 0; j < m; j++) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.push_back(r[i][j]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < n; i++) {
			y[i][j] = lower_bound(v.begin(), v.end(), r[i][j]) - v.begin() + 1;
		}
		maxy[j] = v.size();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int nex = max(x[i][j], y[i][j]);
			int ans = max(maxx[i] + nex - x[i][j], maxy[j] + nex - y[i][j]);
			if (j)printf(" ");
			printf("%d", ans);
		}
		puts("");
	}
	return 0;
}