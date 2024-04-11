#include <bits/stdc++.h>

using namespace std;
#define int long long
int A[1000];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			pair<int, int> Ra = {1, A[i]};
			for(int j = i + 1; j < n; j++){
				if(j % 2 == 1){
					Ra.first -= A[j], Ra.second -= A[j];
					ans += max(0LL, min(Ra.second - Ra.first + 1, max(0LL, 0 - Ra.first + 1)));
					Ra.first = max(0LL, Ra.first);
				}else{
					Ra.first += A[j], Ra.second += A[j];
				}
			}
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}