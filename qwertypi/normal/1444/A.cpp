#include <bits/stdc++.h>

using namespace std;

#define int long long

template<class T>
T binpow(T a, long long b){
	int res(1);
	while(b){
		if(b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void sub(){
	int p, q;
	cin >> p >> q;
	int sp = p;
	if(p % q != 0){
		cout << p << endl;
	}else{
		int ans = 1;
		for(int i = 2; i <= 40000; i++){
			if(q % i == 0){
				int v_p = 0, v_q = 0;
				while(p % i == 0){
					v_p++;
					p /= i;
				}
				while(q % i == 0){
					v_q++;
					q /= i;
				}
				ans = max(ans, sp / (binpow(i, v_p - v_q + 1)));
			}
		}
		if(q != 1){
			int i = q;
			if(q % i == 0){
				int v_p = 0, v_q = 0;
				while(p % i == 0){
					v_p++;
					p /= i;
				}
				while(q % i == 0){
					v_q++;
					q /= i;
				}
				ans = max(ans, sp / binpow(i, v_p - v_q + 1));
			}
		}
		cout << ans << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	} 
}