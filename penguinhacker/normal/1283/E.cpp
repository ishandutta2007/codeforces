#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, amount[200003];

int solve_max() {
	int cnt=0;
	for (int i=1; i<=n; ++i) {
		if (amount[i] == 0)
			continue;
		if (amount[i] == 1) {
			if (amount[i-1]==0) {
				amount[i]=0;
			}
			cnt++;
		}
		else if (amount[i] == 2) {
			if (amount[i-1]==0)
				cnt++;
			else
				amount[i+1]++;
			cnt++;
		}
		else {
			if (amount[i-1]==0) {
				cnt++;
			}
			amount[i+1]++;
			cnt++;
		}
	}
	if (amount[n+1])
		cnt++;
	return cnt;
}

int solve_min() {
	int last=-100;
	int cnt=0;
	int current=0;
	for (int i=1; i<=n+1; ++i) {
		if (amount[i]==0) {
			cnt += (current+2)/3;
			if (current%3==1 && amount[i+1])
				i++;
			current=0;
		}
		else
			current++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<=n+2; ++i)
		amount[i]=0;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		amount[x]++;
	}
	
	cout << solve_min() << ' ' << solve_max() << '\n';

	return 0;
}