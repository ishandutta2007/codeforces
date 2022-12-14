#include "bits/stdc++.h"
using namespace std;

#define MAX 200002


int n;
int q;
vector<long long int> v;
vector<long long int> im;

int main() {
	cin >> n >>q;
	for (int i = 0; i < n; i++) {
		long long int a;
		scanf("%lld", &a);
		v.push_back(a);
	}
	im = v;
	for (int i = 1; i < im.size(); i++) {
		im[i] += im[i - 1];
	}
	int cur = 0;
	long long int use = 0;
	while (q--) {
		if (cur == n) {
			cur = 0;
			use = 0;
		}
		long long int k;
		scanf("%lld", &k);
		{
			long long int rest = v[cur] - use;
			if (rest > k) {
				use += k;
				printf("%d\n", n - cur);
				continue;
			}
			k -= rest;
			cur++;
		}
		use = 0;
		long long int lw = im[cur - 1]+k;
		cur = lower_bound(im.begin(), im.end(), lw) - im.begin();
		if (cur == n) {

		}
		else {
			if (im[cur] == lw) {
				cur++;
			}
			else {
				use = v[cur] - (im[cur] - lw);
			}
		}
		if (cur == n) {
			cur = 0;
			use = 0;
		}
		printf("%d\n", n - cur);
	}
	return 0;
}