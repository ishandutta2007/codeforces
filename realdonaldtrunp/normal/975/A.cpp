#include "bits/stdc++.h"
using namespace std;

int n;

char buf[10002];

string s;
set<string> ss;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		s = buf;
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		ss.insert(s);
	}
	cout << ss.size() << endl;
	return 0;
}