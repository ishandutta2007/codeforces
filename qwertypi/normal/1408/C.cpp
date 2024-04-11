#include <bits/stdc++.h>

using namespace std;

int A[100002];
long double t1[100001], t2[100001];
void sub(){
	int l, n;
	cin >> n >> l;
	A[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i + 1];
	}
	A[n + 1] = l;
	t1[0] = 0, t2[n + 1] = 0;
	for(int i = 0; i <= n; i++){
		t1[i + 1] = t1[i] + (long double) (A[i + 1] - A[i]) / (i + 1);
	}
	
	for(int i = n + 1; i >= 1; i--){
		t2[i - 1] = t2[i] + (long double) (A[i] - A[i - 1]) / (n + 2 - i);
	}
	
	cout << fixed << setprecision(10);
	for(int i = 0; i <= n + 1; i++){
		if(t1[i] > t2[i]){
			long double u = A[i], l = A[i - 1], x;
			while(u - l > 1e-9){
				x = (u + l) / 2;
				if(t1[i - 1] + (x - A[i - 1]) / i > t2[i] + (A[i] - x) / (n + 2 - i)){
					u = x;
				}else{
					l = x;
				}
			}
			long double ans = t1[i - 1] + (x - A[i - 1]) / i;
			cout << ans << endl;
			return;
		}
		
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}