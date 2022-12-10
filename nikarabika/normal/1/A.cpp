#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, n;
	cin >> a >> b >> n;
	cout << (a+n-1)/n * ((b + n-1)/n) << endl;
	return 0;
}