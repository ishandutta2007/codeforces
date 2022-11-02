#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100001];
int s[100001];
int32_t main(){
	int n, k, m;
	cin >> n >> k >> m;
	long double ans = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	for(int i = n - 1; i >= 0; i--){
		s[i] = s[i + 1] + A[i];
	}
	
	for(int i = 0; i < n; i++){
		int qr = m - i; if(qr < 0) continue;
		int ss = s[i] + min(qr, (n - i) * k);
		ans = max(ans, (long double) ss / (n - i));
	}
	cout << setprecision(15) << ans << endl; 
}