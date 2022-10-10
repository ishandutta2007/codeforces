#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	set<string> t;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s);
		cout << ((t.find(s) == t.end()) ? "NO\n" : "YES\n");
		t.insert(s);
	}
	return 0;
}