#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string red(string s) {
	string r;
	for (char c : s)
		if (c!='b')
			r+=c;
	return r;
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	if (red(s)!=red(t)) {
		cout << "NO\n";
		return;
	}
	vector<int> pa(n+1), pc(n+1);
	for (int i=0; i<n; ++i) {
		pa[i+1]=pa[i]+(s[i]=='a');
		pc[i+1]=pc[i]+(s[i]=='c');
	}
	vector<int> p1, p2;
	for (int i=0; i<n; ++i) {
		if (s[i]=='b')
			p1.push_back(i);
		if (t[i]=='b')
			p2.push_back(i);
	}
	for (int i=0; i<p1.size(); ++i) {
		if (p1[i]==p2[i])
			continue;
		if (p1[i]>p2[i]) { // move forwards, cant have c's
			if (pc[p1[i]+1]!=pc[p2[i]]) {
				cout << "NO\n";
				return;
			}
		} else if (pa[p2[i]+1]!=pa[p1[i]]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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