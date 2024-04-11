#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

#define MAX 100002

int n;
vector<long long int> v;

vector<long long int> df;
vector<long long int> sm;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int a;
		scanf("%lld", &a);
		v.push_back(a);
	}
	int q;
	cin >> q;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i+1 < v.size(); i++) {
		long long int dif = v[i + 1] - v[i];
		dif--;
		df.push_back(dif);
	}
	sort(df.begin(), df.end());
	sm = df;
	for (int i = sm.size() - 1; i >= 0; i--) {
		if (i + 1 < sm.size()) {
			sm[i] += sm[i + 1];
		}
	}
	bool outt = false;
	while (q--) {
		long long int l, r;
		scanf("%lld%lld", &l, &r);
		int id = lower_bound(df.begin(), df.end(), r-l) - df.begin();
		long long int rest = 0;
		if (id < df.size()) {
			rest += sm[id];
			rest -= (r-l) * (long long int)(df.size() - id);
		}
		long long int rng = v.back() + r;
		rng -= v[0] + l;
		rng++;
		rng -= rest;
		if (outt)printf(" ");
		outt = true;
		printf("%lld", rng);
	}
	puts("");
	return 0;
}