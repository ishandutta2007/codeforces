#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<string> inp(n);
	for(auto &i : inp) cin >> i;
	reverse(inp.begin(), inp.end());
	set<string> myset;
	vector<string> ans;
	string temp;
	for (int i = 0; i < n; ++i) {
		temp = inp[i];
		if (myset.count(temp) == 0) ans.push_back(temp);
		myset.insert(temp);
	}
	for (auto &i : ans) cout << i << '\n';
	//system("pause");
    return 0;
}