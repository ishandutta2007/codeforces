#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int k, n, w;
	cin >> k >> n >> w;
	cout << max((k * w * (w + 1) / 2) - n, 0 * 1LL) << endl;
	return 0;
}