#include "bits/stdc++.h"
using namespace std;
int n , a , b , c , d;
long long ans = 0;
int main(){
	cin >> n >> a >> b >> c >> d;
	for(int i = 1 ; i <= n ; ++i){
		int c1 = a + b + i;
		int c2 = a + c + i;
		int c3 = b + d + i;
		int c4 = c + d + i;
		int ql = -1e9;
		int qr = 1e9;
		ql = max(ql , 1 + c2 - c1);
		ql = max(ql , 1 + c3 - c1);
		ql = max(ql , 1 + c4 - c1);
		qr = min(qr , n + c2 - c1);
		qr = min(qr , n + c3 - c1);
		qr = min(qr , n + c4 - c1);
		ql = max(ql , 1);
		qr = min(qr , n);
		ans += max(0 , qr - ql + 1);
	}
	cout << ans;
}