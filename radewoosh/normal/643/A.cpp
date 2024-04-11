#include<bits/stdc++.h>
using namespace std;
const int nax = 5005;
int t[nax], cnt[nax], answer[nax];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	for(int low = 1; low <= n; ++low) {
		for(int i = 1; i <= n; ++i)
			cnt[i] = 0;
		int best = 0;
		for(int i = low; i <= n; ++i) {
			int val = t[i];
			++cnt[val];
			if(cnt[val] > cnt[best] || (cnt[val] == cnt[best] && val < best))
				best = val;
			++answer[best];
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d ", answer[i]);
	puts("");
	return 0;
}