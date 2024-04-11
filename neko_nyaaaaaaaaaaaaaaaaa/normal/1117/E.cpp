#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void init() {
	cin >> s;
	n = s.size();
} 

vector<int> query(vector<int> ar) {
	string q[3] = {""};
	string a[3] = {""};

	for (int k: ar) {
		for (int i = 0; i < 3; i++) {
			char c = (k % 26) + 'a';
			q[i].push_back(c);
			k /= 26;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << "? " << q[i] << endl;
		cin >> a[i];
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int k = 0, pw = 1;
		for (int j = 0; j < 3; j++) {
			k += pw*(a[j][i] - 'a');
			pw *= 26;
		}
		ans.push_back(k);
	} 

	return ans;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	init();

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}

	vector<int> ans = query(a);
	cout << "! ";
	
	vector<char> res(n);
	for (int i = 0; i < n; i++) {
		res[ans[i]] = s[i];
	}
	for (char c: res) cout << c;
	cout << endl;

	return 0;
}