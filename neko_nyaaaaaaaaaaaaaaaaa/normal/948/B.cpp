#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> sieve(1000007);

void init() {
	int i = 4;
	while (i <= 1000000) {
		sieve[i] = 2;
		i += 2;
	}
	i = 3;
	while (i <= 1000000) {
		if (sieve[i]) {i += 2; continue;}
		int tmp = i*2;
		while (tmp <= 1000000) {
			sieve[tmp] = i;
			tmp += i;
		}
		i += 2;
	}
}

vector<int> primdiv(int n) {
	vector<int> ans;
	int i = 2;
	while (n > 1) {
		bool flag = 0;
		while (n % i == 0) {
			n /= i;
			flag = 1;
		}
		if (flag) {ans.push_back(i);}
		i++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	init();
	
	int x2;
	cin >> x2;
	int i;
	vector<int> x1;
	for (i = x2; i > x2 - sieve[x2]; i--) {
		if (sieve[i]) {x1.push_back(i);}
	}
	if (x1.size() == 0) {
		cout << x2 - sieve[x2] + 1;
		return 0;
	}
	int x0 = 1e6;
	for (int i = 0; i < x1.size(); i++) {
		x0 = min(x0, x1[i] - sieve[x1[i]] + 1);
	}
	cout << x0;
	
	return 0;
}