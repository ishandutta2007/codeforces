#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	
	set<int> s;
	while (n--) {
		int x;
		cin >> x;
		if (x) s.insert(x);
	}
	cout << s.size();
	
	return 0;
}