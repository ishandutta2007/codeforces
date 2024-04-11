#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int p[10];

void test_case() {
	int a, b, c;
	cin >> a >> b >> c;
	int base=p[c-1];
	cout << p[a-1] << " " << p[c-1]*(p[b-c]+1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	p[0]=1;
	for (int i=1; i<9; ++i)
		p[i]=p[i-1]*10;
	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}