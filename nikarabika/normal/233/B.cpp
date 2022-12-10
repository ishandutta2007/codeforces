#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n;

LL s(LL x){
	LL ret = 0;
	while(x)
		ret += x % 10, x /= 10;
	return ret;
}

LL F(LL x){
	return x * (x + s(x));
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	if(n == 2){
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 0; i < 100; i++){
		LL lo = 0, hi = 1e7 + 1;
		if(F(i) == n){
			cout << i << endl;
			return 0;
		}
		while(hi - lo > 1){
			LL mid = (lo + hi) / 2;
			LL x = F(mid * 100 + i);
			if(x < n)
				lo = mid;
			else if(x > n)
				hi = mid;
			else{
				cout << mid * 100 + i<< endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}