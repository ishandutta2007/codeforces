#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v;
	for (char c : s) if (c != '+') v.push_back(c - '0');
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) cout << v[i] << "+";
	cout << v[v.size() - 1];
}