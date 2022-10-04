#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> vec;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string foo;
		cin >> foo;
		vec.push_back(foo);
	}
	sort(vec.begin(), vec.end(), [](const string& x, const string& y)->bool {return x + y < y + x; });
	for (auto &x : vec) cout << x;
	
}