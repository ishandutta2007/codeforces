#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	long long sums = 0;
	vector<int> l(a);
	vector<double> l1(a);
	for (int i = 0; i < a; i++) {
		int ls;
		cin >> ls;
		l[i] = ls;
		sums += ls;
		l1[i] = sums;
	}
	cout<<endl;
	double maxs = 0;
	for (int i = b; i <= a; i++) {
		int cnt = 0;
		maxs = max(maxs, l1[i - 1] / i);
		for (int j = i+1; j <= a; j++) {
			maxs = max(maxs, (l1[j - 1] - l1[cnt]) / i);
			cnt += 1;
		}
	}
	cout <<  setprecision(30) << maxs;
}