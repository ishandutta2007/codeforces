#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int lb, rb, a[1000000];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	lb=0; rb=s.size()-1;
	for (int i=0; i<s.size(); ++i) {
		if (s[i]=='l') {
			a[rb]=i+1;
			rb--;
		}
		else {
			a[lb]=i+1;
			lb++;
		}
	}
	for (int i=0; i<s.size(); ++i)
		cout << a[i] << '\n';
	return 0;
}