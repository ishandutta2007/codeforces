#include <bits/stdc++.h>
#define int long long
int ans = 0;
using namespace std;

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
	for(auto i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59}){
		if(x == i) return true;
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
	int x, d;
	cin >> x >> d;
	int c = 0;
	while(x % d == 0) c++, x /= d;
	if(c < 2){
		cout << "NO" << endl;
		return;
	}
	if(x != 1 && !MR(x)){
		cout << "YES" << endl;
		return;
	}
	if(c <= 2){
		cout << "NO" << endl;
		return;
	}
	x *= d; c--;
	map<int, int> M1, M2;
	for(int i = 2; i * i <= x; i++){
		while(x % i == 0) M1[i]++, x /= i;
	}
	if(x != 1) M1[x]++;
	for(int i = 2; i * i <= d; i++){
		while(d % i == 0) M2[i]++, d /= i;
	}
	if(d != 1) M2[d]++;
	int explode = 0;
	for(auto p : M2){
		if(M1.find(p.first) != M1.end()){
			if(M1[p.first] > c * (p.second - 1)) explode++;
		}
	}
	if(M2.size() == 1){
		if(explode){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}else{
		cout << "YES" << endl;
	}
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}