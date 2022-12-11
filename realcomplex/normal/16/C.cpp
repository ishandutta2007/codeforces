#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll h,w,x,y;
	cin >> h >> w >> x >> y;
	ll k = __gcd(x,y);
	x/=k;	
	y/=k;
	ll lef = 0,rit = 2e9;
	ll take;
	while(rit-lef>1){
		take = (rit+lef)/2;
		if((x*take)<=h&&(y*take)<=w){
			lef = take;
		}
		else{
			rit = take;
		}	
	}
	cout << lef*x << " " << lef*y;
	return 0;
}