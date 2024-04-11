#include <bits/stdc++.h>

using namespace std;

int A[200001];
int bl[200001][20];
int main(){
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
			bl[i][0] = A[i];
		}
		for(int j = 1; j < 20; j++){
			for(int i = 0; i < n; i++){
				bl[i][j] = __gcd(bl[i][j - 1], bl[(i + (1 << j - 1)) % n][j - 1]);
			}
		}
		int g = 0;
		for(int i = 0; i < n; i++){
			g = __gcd(g, A[i]);
		}
		int ans = 0;
		bool all_equal = true;
		for(int i = 0; i < n; i++){
			if(A[i] != g) all_equal = false;
		}
		if(all_equal){
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			int len = 1, val = A[i];
			for(int j = 19; j >= 0; j--){
				if(__gcd(val, bl[(i + len) % n][j]) != g) val = __gcd(val, bl[(i + len) % n][j]), len += (1 << j);
			}
			if(val != g) len++;
			ans = max(ans, len);
		}
		cout << ans - 1 << endl;
	}
}