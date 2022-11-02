#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

int A[200001];
int bl[200001][20];

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		for(int i = 0; i < n - 1; i++){
			bl[i][0] = abs(A[i] - A[i + 1]);
		}
		for(int j = 1; j < 20; j++) for(int i = 0; i < n - (1 << j); i++) bl[i][j] = __gcd(bl[i][j - 1], bl[i + (1 << j - 1)][j - 1]); 
		int ans = 0;
		for(int i = 0; i < n; i++){
			int l = 0, val = 0;
			for(int j = 19; j >= 0; j--){
				if(i + l + (1 << j) <= n - 1 && __gcd(val, bl[i + l][j]) != 1){
					val = __gcd(val, bl[i + l][j]); l += (1 << j); // I have made this mistake 3 times today. Swapping the order. WTF
				}
			}
			ans = max(ans, l + 1);
		}
		cout << ans << endl;
	}
}