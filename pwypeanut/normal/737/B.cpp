#include <bits/stdc++.h>
using namespace std;

int N, A, B, K;
string s;
vector< pair<int, int> > v;
vector<int> ans;

int main() {
	scanf("%d%d%d%d", &N, &A, &B, &K);
	cin >> s;
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			if (cur > 0) v.push_back(make_pair(i - cur, cur));
			cur = 0;
		} else cur++;
	}
	if (cur > 0) v.push_back(make_pair(N - cur, cur));
	int total = 0;
	for (int i = 0; i < v.size(); i++) total += v[i].second / B;
	printf("%d\n", total - A + 1);
	int needed = total - A + 1;
	for (int i = 0; i < v.size(); i++) {
		int has = v[i].second / B;
		int used = min(has, needed);
		for (int j = 0; j < used; j++) {
			ans.push_back(v[i].first + (B - 1) + j * B);
		}
		needed -= used; 
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}