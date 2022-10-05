#include <bits/stdc++.h>
using namespace std;

int n,s=1;
char c;
vector<int> x = { 1 };

int main() {
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'f') x.insert(x.begin(), 0),s++;
		else for (int i = s - 2; i >= 0; i--)
			(x[i] += x[i + 1]) %= int(1e9+7);
	}
	cout<<x[0];
}