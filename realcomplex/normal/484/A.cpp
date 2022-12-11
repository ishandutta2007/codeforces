#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int test_cases;
	cin >> test_cases;
	ll l, r;
	for(int i = 0; i < test_cases; i ++ ){
		cin >> l >> r;
		for(ll j = 0; j < 60; j ++ ){
			if((l | (1ll << j)) <= r){
				l |= (1ll << j);
			}
		}
		cout << l << "\n";
	}
	return 0;
}