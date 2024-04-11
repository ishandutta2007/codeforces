#include <bits/stdc++.h>
using namespace std;

int main() {
	int r; cin >> r;
	vector<int> bounds = {1200,1400,1600,1900,2100,2300,2400,2600,3000};
	int i = 0;
	while (bounds[i] <= r) i++;
	cout << bounds[i] << '\n';
}