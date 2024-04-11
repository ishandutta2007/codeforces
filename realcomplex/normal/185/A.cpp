#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define mod ll(1000000007)

ll n,x,y;

int main(){
	cin >> n;
	x = 1,y = 2;
	while(n){
		if(n%2)
			x = (x*y)%mod;
		y = (y*y)%mod;
		n/=2;
	}
	cout << ((x*x+x)/2)%mod << "\n";
	return 0;
}