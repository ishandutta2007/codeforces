#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int cnt, n;
string s;
vector<int> r; //removed

void solve() {
	cnt=0;
	r.clear();

	cin >> s;
	n = s.size();
	s += "zz";
	for (int i=0; i<n-2; ++i) {
		if (s[i]=='t' && s[i+1]=='w' && s[i+2]=='o') {
			if (s[i+3]=='n') {
				r.push_back(i+3);
				i+=3;
			}
			else {
				r.push_back(i+2);
				i+=2;
			}
			cnt++;
		}
		else if (s[i]=='o' && s[i+1]=='n' && s[i+2]=='e') {
			r.push_back(i+2);
			i+=2;
			cnt++;
		}
	}

	cout << cnt << '\n';
	for (int i : r)
		cout << i << ' ';
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