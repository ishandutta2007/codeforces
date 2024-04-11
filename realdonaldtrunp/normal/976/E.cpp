#include "bits/stdc++.h"
using namespace std;

#define MAX 200002

int n;
int a;
int b;

vector<pair<long long int, long long int> > v;


vector<pair<long long int, int> > inc;

map<int, int> ty;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		long long int c, d;
		scanf("%lld%lld", &c, &d);
		v.push_back(make_pair(c, d));
		inc.push_back(make_pair(max(0LL, c-d), i));
	}
	for (int i = 0; i <= b; i++) {
		inc.push_back(make_pair(0LL, -11));
		inc.push_back(make_pair(0LL, -11));
	}
	ty[-1] = 11111111;
	sort(inc.begin(), inc.end());
	reverse(inc.begin(), inc.end());
	for (int i = 0; i < inc.size(); i++) {
		ty[inc[i].second] = i;
		if (i)inc[i].first += inc[i - 1].first;
	}
	long long int ans = 0;
	for (int i = -1; i < n; i++) {
		int ch = b;
		long long int add = 0;
		if (i >= 0&&b) {
			long long int val = v[i].first;
			for (int j = 0; j < a; j++) {
				val *= 2LL;
			}
			if (val > v[i].second) {
				ch--;
				add = val - v[i].second;
			}
			else {
				continue;
			}
		}
		int till = ch - 1;
		if (till >= 0) {
			if (till >= ty[i] && i != -1) {
				till++;
				add -= max(0LL, v[i].first - v[i].second);
			}
			add += inc[till].first;
		}
		ans = max(ans, add);
	}
	for (int i = 0; i < v.size(); i++) {
		ans += v[i].second;
	}
	printf("%lld\n", ans);
	return 0;
}