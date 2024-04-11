#include <bits/stdc++.h>

using namespace std;

int A[200001];
int ans[5000001][2];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int s = A[i] + A[j];
			if(ans[s][0] != 0 && ans[s][0] != i + 1 && ans[s][0] != j + 1 && ans[s][1] != i + 1 && ans[s][1] != j + 1){
				cout << "YES" << endl;
				cout << ans[s][0] << ' ' << ans[s][1] << ' ' << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}else if(ans[s][0] != 0){
				continue;
			}else{
				ans[s][0] = i + 1, ans[s][1] = j + 1;
			}
		}
	}
	cout << "NO" << endl;
}