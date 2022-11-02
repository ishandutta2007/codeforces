#include <bits/stdc++.h>

using namespace std;

int A[100001];
bool used[100001];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				A[i] = -1;
			}else if(s[i] == '0'){
				A[i] = 0;
			}else{
				A[i] = 1;
			}
		}
		fill(used, used + n, 0);
		for(int i = 0; i < n; i++){
			if(A[i] == -1){
				ans += 2;
			}else if(A[i] == 0){
				if(i > 0 && A[i - 1] == 1 && !used[i - 1]){
					ans += 2;
					used[i - 1] = true;
				}else if(i != n - 1 && A[i + 1] == 1 && !used[i + 1]){
					ans += 2;
					used[i + 1] = true;
				}else{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}