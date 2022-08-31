#include <bits/stdc++.h>
using namespace std;
const int nax = 105;
pair<int, int> t[nax];
int diff[nax];
bool done[nax];
bool cmp(pair<int,int> a, pair<int,int> b) {
	return make_pair(a.first, -a.second) < make_pair(b.first, -b.second); 
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, d;
		scanf("%d%d", &a, &d);
		t[i] = make_pair(a, i);
		diff[i] = d;
	}
	sort(t, t + n, cmp);
	int ans = 0;
	for(int rep = 0; rep < 2; ++rep) {
		for(int tries = 0; tries < n; ++tries) {
			sort(t, t + n, cmp);
			if(rep) reverse(t, t + n);
			for(int i = 0; i < n; ++i) {
				int id = t[i].second;
				if(done[id]) continue;
				if(diff[id] <= 0 && rep == 0) continue;
				if(diff[id] >= 0 && rep == 1) continue;
				done[id] = true;
				int A = 0;
				for(int j = 0; j < n; ++j)
					if(cmp(t[i], t[j])) ++A;
				t[i].first += diff[id];
				sort(t, t + n, cmp);
				int B = 0;
				for(int j = 0; j < n; ++j)
					if(t[j].second == id) {
						i = j;
						break;
					}
				for(int j = 0; j < n; ++j)
					if(cmp(t[i], t[j])) ++B;
				ans += abs(A - B);
				break;
			}
		}
	}
	printf("%d\n", ans);
	//for(int i = n - 1; i >= 0; --i) {
	//	int id = t[i].second;
}