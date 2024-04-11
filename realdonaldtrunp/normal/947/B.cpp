#include"bits/stdc++.h"

using namespace std;


priority_queue<long long int,vector<long long int>,greater<long long int> > q;
int n;
vector<long long int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	long long int base = 0;
	long long int sum = 0;
	long long int ADD = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		q.push(v[i] + base);
		sum += v[i];
		base += t;
		ADD += v[i];
		while (!q.empty()&&(q.top() - base <= 0)) {
			sum -= q.top() - (base - t);
			q.pop();
		}
		sum -= (long long int)(t)*(long long int)(q.size());
		if (i)printf(" ");
		printf("%lld", ADD-sum);
		ADD -= (ADD - sum);
	}
	puts("");
	return 0;
}