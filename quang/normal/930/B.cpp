#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n;
char s[N];
vector<int> a[100];
int cnt[30];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = n + 1; i <= n * 2; i++) {
		s[i] = s[i - n];
		a[s[i] - 'a'].push_back(i - n);
	}
	double res = 0.;
	for (int i = 0; i < 26; i++) {
		if (a[i].size() == 0) {
			continue;
		}
		int mx = 0;
		for (int add = 1; add < n; add++) {
			memset(cnt, 0, sizeof cnt);
			for (int u : a[i]) {
				cnt[s[u + add] - 'a']++;
			}
			int sum = 0;
			for (int j = 0; j < 26; j++) {
				sum += cnt[j] == 1;
			}
			mx = max(mx, sum);
		}
		// cout << i << " " << mx << endl;
		res += 1. * mx / n;
	}
	printf("%.10f\n", res);
	return 0;
}