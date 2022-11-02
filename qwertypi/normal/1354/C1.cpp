#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PI 3.1415926535
void sub(){
	int n;
	cin >> n;
	cout << setprecision(10) << fixed;
	if(n % 2 == 0){
		double ans = 0;
		for(int i = 1; i < n / 2; i++){
			ans += sin(PI / 2 * i / (n / 2));
		}
		ans *= 2;
		ans++;
		cout << ans << endl;
	}else{
		
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}