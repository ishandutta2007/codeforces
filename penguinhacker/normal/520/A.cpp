#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<bool> oc(26);
	for (char c : s)
		oc[tolower(c)-'a']=1;
	cout << (count(oc.begin(), oc.end(), 1)==26?"YES":"NO");
	return 0;
}