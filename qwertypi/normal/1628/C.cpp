#include <bits/stdc++.h>

using namespace std;

int xored[4000][4000];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> xored[i][j];
	int ans = 0;
	for(int i = 0; i < n * 2 - 1; i += 4){
		if(i < n){
			for(int x = 0; x < n && i - x >= 0; x += 2){
				ans ^= xored[x][i - x];
			}
		}else{
			for(int x = n - 1; x >= 0 && i - x < n; x -= 2){
				ans ^= xored[x][i - x];
			}
		}
	} 
	for(int i = 0; i < n; i++){
		reverse(xored[i] + 0, xored[i] + n);
	}
	for(int i = 0; i < n * 2 - 1; i += 4){
		if(i < n){
			for(int x = 0; x < n && i - x >= 0; x += 2){
				ans ^= xored[x][i - x];
			}
		}else{
			for(int x = n - 1; x >= 0 && i - x < n; x -= 2){
				ans ^= xored[x][i - x];
			}
		}
	} 
	cout << ans << endl; 
}

int main(){
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}