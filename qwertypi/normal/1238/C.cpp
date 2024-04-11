#include <bits/stdc++.h>

using namespace std;

int A[200000];
void sub(){
	int h, n;
	cin >> h >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int ans = 0;
	for(int i = 0; i < n - 1; i++){
		if(A[i] - A[i + 1] >= 2){
			A[i] = A[i + 1] + 1;
			i--;
		}else{
			if(i <= n - 3){
				if(A[i + 2] == A[i] - 2){
					i++;
					continue;
				}else{
					ans++;
					A[i + 1] = A[i + 2] + 1;
				}
			}else{
				if(A[n - 1] == 1){
					continue;
				}else{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}