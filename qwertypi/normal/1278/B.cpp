#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[26];
int act[26];

void f(bool x){
	if(x){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
void sub(){
	int a, b;
	cin >> a >> b;
	int diff = abs(a - b);
	int L = max((double) 0 , floor(sqrt(diff * 2)) - 4);
	int R = ceil(sqrt(diff * 2)) + 4;
	for(int i = L; i <= R; i++){
		if(i * (i + 1) / 2 >= diff) {
			if((i + 1) % 4 == 0 || i % 4 == 0){
				if(diff % 2 == 0){
					cout << i << endl;
					return;
				}
			}else{
				if(diff % 2 == 1){
					cout << i << endl;
					return;
				}
			}
		}
	}
}

int32_t main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		sub();
	}
}