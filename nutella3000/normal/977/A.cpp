#include <bits/stdc++.h>

using namespace std;

long long const INF = 1LL << 60;


int main() {
#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
#endif

 	int n, k;
 	cin >> n >> k;
 	while(k--) {
 		if (n % 10 == 0) n /= 10;
 		else n--;
 	}
 	cout << n;
}