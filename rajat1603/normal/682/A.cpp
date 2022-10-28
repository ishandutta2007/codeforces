#include "bits/stdc++.h"
using namespace std;
int n , m;
long long ans;
int main(){
	cin >> n >> m;
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int x = (i % 5);
		int rem = (5 - x);
		if(rem <= m)
			ans += 1 + ((m - rem) / 5);
	}
	cout << ans;
}