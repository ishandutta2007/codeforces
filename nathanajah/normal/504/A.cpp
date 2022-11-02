#include <bits/stdc++.h>
using namespace std;

int n,i;
int deg[100005];
int s[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &deg[i], &s[i]);
	}
	queue <int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
	vector <pair<int,int> > daftar;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (deg[now] == 1) {
			deg[s[now]]--;
			deg[now]--;
			daftar.push_back(make_pair(now, s[now]));
			if (deg[s[now]] == 1) {
				q.push(s[now]);
			}
			s[s[now]] ^= now;
			s[now] = 0;
		}
	}
	printf("%d\n", daftar.size());
	for (int i = 0; i < daftar.size(); i++) {
		printf("%d %d\n", daftar[i].first, daftar[i].second);
	}
}