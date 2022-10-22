#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
void test_case() {
	cin >> n >> m;
	int x=abs(n-m);
	cout << (x+9)/10 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) test_case();
	return 0;
}