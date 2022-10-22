#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, pos[100000], cnt[100000];

void solve() {
	cin >> n;
	int last=n-1;
	for (int i=0, a; i<n; ++i) {
		cin >> a, a--;
		pos[a]=i;
		cnt[i]=1;
	}
	int start, curr;
	bool hasEnded=1;
	for (int i=0; i<n; ++i) {
		if (hasEnded) {
			start=pos[i];
			curr=pos[i];
			hasEnded=0;
		}
		else {
			if (pos[i]==curr+1)
				curr++;
			else {
				cout << "No\n";
				return;
			}
		}
		if (pos[i]==last) {
			hasEnded=1;
			last=start-1;
		}
	}
	cout << "Yes\n";
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