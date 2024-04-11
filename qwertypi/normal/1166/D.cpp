#include <bits/stdc++.h>
#define int long long
#define INF (1LL << 56)
using namespace std;

int A[61];
int sA[61];
int de[61];
int32_t main(){
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int a, b, m;
		cin >> a >> b >> m;
		if(a > b){
			cout << -1 << endl;
			continue;
		}
		if(a == b){
			cout << 1 << ' ' << a << endl;
			continue;
		}
		if(b - a <= m){
			cout << 2 << ' ' << a << ' ' << b << endl;
			continue;
		}
		bool done = false;
		for(int j = 3; j <= 50; j++){
			bool fail = false;
			A[0] = a;
			sA[0] = a;
			for(int k = 1; k < j; k++){
				A[k] = sA[k - 1] + 1;
				sA[k] = sA[k - 1] + A[k];
				if(A[k] > b){
					fail = true;
					break;
				}
			}
			if(fail) continue;
			/*
			for(int i = 0; i < j; i++){
				cout << A[i] << ' ';
			}
			cout << endl;
			*/
			int diff = b - A[j - 1];
			// cout << diff << endl;
			for(int k = 1; k < j; k++){
				int d = (1LL << max(0LL, j - k - 2));
				// cout << diff << ' ' << d << ' ' << m - 1 << endl;
				int g = min(diff / d, m - 1);
				de[k] = g;
				diff -= g * d;
			}
			if(diff != 0) continue;
			for(int k = 1; k < j; k++){
				A[k] = sA[k - 1] + de[k] + 1;
				sA[k] = sA[k - 1] + A[k];
			}
			done = true;
			cout << j << ' '; 
			for(int i = 0; i < j; i++){
				cout << A[i] << ' ';
			}
			cout << endl;
			break;
		}
		if(!done) cout << -1 << endl;
	}
}