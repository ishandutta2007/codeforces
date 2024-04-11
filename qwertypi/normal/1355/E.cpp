#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[100000];
int prec[100001];
int ans = (1LL << 60);

int n, a, r, m;
void check(int t){
	int _l = 0, _r = 0;
	for(int i = 0; i < n; i++){
		if(t > A[i]){
			_l += t - A[i];
		}else{
			_r += A[i] - t;
		}
	}
	int g = min(_l, _r);
	ans = min(ans, g * m + a * (_l - g) + r * (_r - g));
}

int32_t main(){
	cin >> n >> a >> r >> m;
	m = min(a + r, m);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	for(int i = 0; i < n; i++){
		prec[i + 1] = prec[i] + A[i];
	}
	for(int i = 0; i < n; i++){
		int _l = (i + 1) * A[i] - prec[i + 1], _r = prec[n] - prec[i + 1] - (n - i - 1) * A[i];
		int g = min(_l, _r);
		ans = min(ans, g * m + a * (_l - g) + r * (_r - g));
	}
	
	int diff = prec[n] - A[0] * n;
	int t = diff / n;
	check(A[0] + t - 1);
	check(A[0] + t);
	check(A[0] + t + 1);
	cout << ans << endl;
}