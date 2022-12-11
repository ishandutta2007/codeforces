#include <bits/stdc++.h>
using namespace std;

const int mx = (1e6)+1;

int k[mx];

int main() {
	int ai;
	for(int i = 1;i<=1e6;i++){
		ai = i;
		while(ai<=1e6){
			k[ai]++;
			ai+=i;
		}
	}
	int a,b,c;
	cin >> a >> b >> c;
	int mod = pow(2,30);
	int val = 0;
	for(int i = 1;i<=a;i++){
		for(int x = 1;x<=b;x++){
			for(int y = 1;y<=c;y++){
				val += k[i*x*y];
				val %= mod;
			}
		}
	}
	cout << val;
	return 0;
}