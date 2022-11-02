#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100];

int pow(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res *= a;
		}
		a *= a;
		b /= 2;
	}
	return res;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		for(int i = 0; pow(m, i) <= (1LL << 55); i++){
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += (A[j] / pow(m, i)) % m;
			}
			if(sum >= 2){
				cout << "No" << endl;
				goto End;
			}
		}
		cout << "Yes" << endl;
		End:;
	}
}