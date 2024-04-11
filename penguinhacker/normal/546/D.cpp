#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int num[5000001];
ll pref[5000001];

void calc() {
	num[1] = 0;
	for (int i=2; i<=5000000; ++i) {
		bool prime = 1;
		for (int j=2; j*j<=i; ++j) {
			if (i%j == 0) {
				num[i] = num[i/j]+1;
				prime = 0;
				break;
			}
		}
		if (prime) num[i] = 1;
	}
	pref[0] = 0;
	for (int i=1; i<=5000000; ++i)
		pref[i] = pref[i-1] + num[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	calc();
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << pref[a]-pref[b] << '\n';
	}
	return 0;
}