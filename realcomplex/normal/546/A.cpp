#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll f(ll sk){
	return ((sk * (sk - 1)) / 2) + sk;
}
 
int main() {
 
	ll a,b,c;
	cin >> a >> b >> c;
	ll total = a * f(c);
	if(total > b){
		cout << total - b;
	}
	else{
		cout << 0;
	}
	return 0;
}