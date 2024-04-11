#include <bits/stdc++.h>
#define int long long
int ans = 0;
using namespace std;
// Thank you for ka long long.
int bp(int a, int b, int p){
	if(b == 0) return 1;
	return bp(a * a % p, b / 2, p) * (b % 2 ? a : 1) % p;
}

int mi(int a, int p){
	return bp(a, p - 2, p);
}

bool MR(int x){
	if(x == 1) return false;
	int v = x - 1, d = 0;
	while(v % 2 == 0) v /= 2, d++;
	for(auto i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 53, 59}){
		bool suc = false;
		int pw = bp(i, v, x);
		if(pw == 1) suc = true;
		for(int j = 0; j < d; j++){
			if(pw == x - 1) suc = true;
			pw = bp(pw, 2, x);
		}
		if(!suc) return false;
	}
	return true;
}

void solve(){
	int x;
	cin >> x;
	if(x == 1){
		cout << -1 << endl;
		return;
	}
	if(x % 2 == 1){
		cout << 2 << endl;
		return; 
	}
	int v = x, d = 0;
	while(v % 2 == 0) v /= 2, d++;
	if(v == 1){
		cout << -1 << endl;
	}else if(v > (1LL << d + 1)){
		cout << (1LL << d + 1) << endl;
		return;
	}else{
		cout << v << endl;
	}
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}