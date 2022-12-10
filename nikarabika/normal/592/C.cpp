#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int LL;
typedef long double LD;

void print(LL x, LL y){
	cout << x / __gcd(x, y) << '/' << y / __gcd(x, y) << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL t, w, b, gcd, soor;
	cin >> t >> w >> b;
	gcd = __gcd(w, b);
	soor = min(t, min(w, b) - 1);
	if(t % w == 0){
		if(t / w < b / gcd){
			print(soor, t);
			return 0;
		}
	}
	else{
		if(LD(t) / LD(w) < LD(b) / LD(gcd)){
			print(soor, t);
			return 0;
		}
	}
	LL len = w / gcd * b;
	soor += ((t / len) - 1) * min(w, b) + min((t % len) + 1, min(w, b));
	print(soor, t);
	return 0;
}