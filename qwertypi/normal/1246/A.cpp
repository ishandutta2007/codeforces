#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll A[100];

int f(ll x){
	int res = 0;
	while(x){
		if(x % 2)
			res++;
		x /= 2;
	}
	return res;
}
int main(){
	int n, p;
	cin >> n >> p;
	for(int i = 0; i < 40; i++){
		A[i] = (1LL << i) + p;
	}
	ll g = 0;
	for(int i = 0; i < 40; i++){
		g = __gcd(A[i], (ll)g);
	}
	int curAns = 0;
	while(true){
		ll req = (ll)n - curAns * p;
		if(f(req) <= curAns && req >= curAns){
			cout << curAns;
			return 0;
		}
		curAns++;
		if(req < 0){
			break;
		}
	}
	cout << -1;
}