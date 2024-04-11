#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200000];
int cnt[20];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 20; j++){
			if((1 << j) & A[i]){
				cnt[j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x = 0;
		for(int j = 0; j < 20; j++){
			if(cnt[j] > 0){
				cnt[j]--;
				x += (1 << j);
			}
		}
		ans += x * x;
	}
	cout << ans << endl;
}