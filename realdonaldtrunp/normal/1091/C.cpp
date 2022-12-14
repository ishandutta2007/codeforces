#include"bits/stdc++.h"
using namespace std;

long long int n;
vector<long long int> v;
vector<long long int> ans;
int main() {
	cin >> n;
	for (long long int i = 1; i*i <= n; i++) {
		if (n%i == 0LL) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		long long int beg = 1;
		long long int en = n+1-v[i];
		long long int len = (en - beg) / v[i] + 1LL;
		long long int sum = (beg + en)*len / 2LL;
		ans.push_back(sum);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i)printf(" ");
		printf("%lld", ans[i]);
	}
	puts("");
	return 0;
}