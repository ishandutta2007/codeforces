#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s, curr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (char c : s) {
		if (!curr.empty()&&c==curr.back())
			curr.pop_back();
		else
			curr.push_back(c);
	}
	cout << (curr.empty()?"Yes":"No");
	return 0;
}