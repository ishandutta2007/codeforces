#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[200000], colors[200000];
bool pos1, pos2;

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	
	pos1=1;
	pos2=0;

	for (int i=0; i<n; ++i) {
		if (a[i]!=a[(i+1)%n]) {
			pos1=0;
			break;
		}
	}
	if (pos1) {
		cout << 1 << '\n';
		for (int i=0; i<n; ++i)
			cout << 1 << ' ';
		cout << '\n';
		return;
	}
	
	int x;
	colors[0] = 0;
	for (int i=1; i<n; ++i) {
		colors[i] = colors[i-1]^1;
	}
	for (int i=0; i<n; ++i) {
		if (a[i]==a[(i+1)%n]) {
			pos2=1;
			x = i;
			break;
		}
	}
	if (n%2==0)
		pos2=1;

	if (pos2) {
		cout << 2 << '\n';
		if (n%2==0) {
			for (int i=0; i<n; ++i)
				cout << colors[i]+1 << ' ';
		}
		else {
			colors[x]=0;
			colors[(x+1)%n]=0;
			for (int i=0; i<n-2; ++i) {
				colors[(x+2+i)%n] = colors[(x+1+i)%n]^1;
			}
			for (int i=0; i<n; ++i) {
				cout << colors[i]+1 << ' ';
			}
		}
		cout << '\n';
		return;
	}

	colors[n-1]=2;
	cout << 3 << '\n';
	for (int i=0; i<n; ++i)
		cout << colors[i]+1 << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}