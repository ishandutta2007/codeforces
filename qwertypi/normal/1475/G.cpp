#include <bits/stdc++.h>

using namespace std;

int A[200001];
int cnt[200001];
int d[200001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		fill(d, d + 200001, 0); fill(cnt, cnt + 200001, 0);
		for(int i = 0; i < n; i++) cin >> A[i], cnt[A[i]]++; 
		d[1] = cnt[1];
		for(int i = 1; i <= 200000; i++){
			for(int j = i * 2; j <= 200000; j += i){
				d[j] = max(d[i] + cnt[j], d[j]);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) ans = max(ans, d[A[i]]);
		cout << n - ans << endl;
	}
}