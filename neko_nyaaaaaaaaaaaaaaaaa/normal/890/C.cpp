#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	long n, x;
	cin >> n;
	if (n == 1) {cout << 1; return 0;}
	
	vector<long> a(n+1, 1);
	vector<long> room(200001, -1);
	
	long ans = 1;
	
	for (long i = 1; i <= n; i++) {
	      cin >> a[i];
	}
	room[1] = 0;
	
	for (long i = 1; i <= n; i++) {
	      if (a[i] == room[a[a[i]]]) {
	            room[a[a[i]]] = i;
	            a[i] = a[a[i]];
	      } else {
	            ans++;
	            room[ans] = i;
	            a[i] = ans;
	      }
	}
	cout << ans;
	
	
	return 0;
}