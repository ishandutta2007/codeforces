#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<long long> sum(n+1);
	for (int i = 0; i < n; i++) sum[i+1] = sum[i]+a[i];
	
	auto avg = [&](int i, int j) { return double(sum[j]-sum[i])/(j-i); };

	stack<int> st;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (!st.empty() && avg(st.top(),j) > avg(j,i+1)) j = st.top(), st.pop();
		st.push(j);
	}
	
	vector<double> res(n);
	int i = n;
	while (!st.empty()) {
		int j = st.top();
		st.pop();
		for (int k = j; k < i; k++) res[k] = avg(j,i);
		i = j;
	}

	for (int i = 0; i < n; i++) {
		printf("%.10f\n", res[i]);
	}
}