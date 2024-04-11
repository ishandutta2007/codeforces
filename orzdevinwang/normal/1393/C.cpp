#include<bits/stdc++.h>
#define N 110000
using namespace std;
priority_queue< pair<int, int> > q;
int T, n, x, a[N], mp[N];
int s[N];
bool cheak(int mid) {
	++mid;
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; i++) mp[i] = s[i] = 0;
	for(int i = 1; i <= n; i++) mp[a[i]]++;
	for(int i = 1; i <= n; i++) if(mp[i]) q.push(make_pair(mp[i], i));
	for(int i = 1; i <= n; i++) {
		if(s[i]) q.push(make_pair(mp[s[i]], s[i]));
		if(q.empty()) return 0;
		int u = q.top().second;
		q.pop(), mp[u]--;
		if(!mp[u]) continue;
		if(i + mid > n) return 0;
		s[i + mid] = u;
	}
	return 1;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int L = 0, R = n - 1;
		while(L < R) {
			int mid = (L + R) / 2 + 1;
			if(cheak(mid)) L = mid;
			else R = mid - 1;
		}
		printf("%d\n", L);
	}
	return 0;
}