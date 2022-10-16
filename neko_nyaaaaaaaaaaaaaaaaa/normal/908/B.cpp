#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
string s;

void go(vector<char> k, pair<int, int> start, vector<string> a) {
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == k[0]) {start.first--;}
		if (s[i] == k[1]) {start.first++;}
		if (s[i] == k[2]) {start.second--;}
		if (s[i] == k[3]) {start.second++;}
		if (start.first >= n || start.first < 0) {return;}
		if (start.second >= m || start.second < 0) {return;}
		if (a[start.first][start.second] == '#') {return;}
		if (a[start.first][start.second] == 'E') {ans++; return;}
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	
	cin >> n >> m;
	pair<int, int> start;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {start.first = i; start.second = j;}
		}
	}
	cin >> s;
	vector<char> k = {'0', '1', '2', '3'};
	do {
		go(k, start, a);
	} while (next_permutation(k.begin(), k.end()));
	cout << ans;
	return 0;
}