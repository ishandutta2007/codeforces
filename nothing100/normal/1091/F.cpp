# include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
long long a[maxn];
char s[maxn];

int main() {
	int n; scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) ans += a[i];
	int first_W = n + 1;
	for(int i = 1; i <= n; ++i) if(s[i] == 'W') {first_W = i; break;}
	stack<int> SG, SW;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'L') {
			while(a[i] > 0 && !SW.empty()) {
					int k = SW.top();
					long long y = min(a[i], a[k]);
					a[k] -= y; a[i] -= y;
					ans += y * 2;
					if(a[k] == 0) SW.pop();
			}
			while(a[i] > 0 && !SG.empty()) {
					int k = SG.top();
					long long y = min(a[i], a[k]);
					a[k] -= y; a[i] -= y;
					ans += y * 4;
					if(a[k] == 0) SG.pop();
			}
			if(a[i] > 0) {
				if(first_W < i) {
					ans += 3 * a[i];
				} else {
					ans += 5 * a[i];
				}
			}
		}
		if(s[i] == 'G') SG.push(i);
		if(s[i] == 'W') SW.push(i);
	}
	while(!SG.empty()) SG.pop();
	while(!SW.empty()) SW.pop();
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'G' && a[i] > 0) {
			while(a[i] > 0 && !SW.empty()) {
				int k = SW.top();
				long long y = min(a[i], a[k]);
				a[k] -= y; a[i] -= y;
				ans += y * 2;
				if(a[k] == 0) SW.pop();
			}
			if(a[i] > 0) {
				ans += 2 * a[i];
			}
		}
		if(s[i] == 'W' && a[i] > 0) SW.push(i);
	}
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'W' && a[i] > 0) ans += a[i];
	}
	printf("%lld\n", ans);
}