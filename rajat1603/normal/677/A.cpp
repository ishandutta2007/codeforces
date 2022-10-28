#include "bits/stdc++.h"
using namespace std;
int n , h;
int inp;
int ans;
int main(){
	cin >> n >> h;
	ans = 0;
	while(n--){
		cin >> inp;
		ans += 1 + (inp > h);
	}
	cout << ans;
}