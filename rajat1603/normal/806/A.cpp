#include "bits/stdc++.h"
using namespace std;
int t;
long long x , y;
long long p , q;
pair < long long , long long > check(long long mid){
	return make_pair(x , x + mid * q - y);
}
int main(){
	cin >> t;
	while(t--){
		cin >> x >> y >> p >> q;
		if(p == q && x < y){
			cout << -1 << endl;
		}
		else if(p == 0 && x > 0){
			cout << -1 << endl;
		}
		else{
			if(x * q == p * y){
				cout << 0 << endl;
			}
			else{
				long long l = 1;
				l = max(l , (y + q - 1) / q);
				long long r = 2e9;
				if(x * q < p * y){
					while(l < r){
						long long mid = l + r >> 1;
						if(check(mid).second < mid * p){
							l = mid + 1;
						}
						else{
							r = mid;
						}
					}
				}
				else{
					while(l < r){
						long long mid = l + r >> 1;
						if(check(mid).first > mid * p){
							l = mid + 1;
						}
						else{
							r = mid;
						}
					}
				}
				cout << l * q - y << endl;
			}
		}
	}
}