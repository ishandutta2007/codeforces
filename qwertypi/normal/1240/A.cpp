#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll A[200000];

int x, a, y, b;

int n;

bool test(ll t, int _n){
	int curInd = n - 1;
	ll cnt = 0;
	int best = _n / ((ll)a * b / __gcd(a, b));
	int _a = _n / a - best;
	int _b = _n / b - best;
	for(int i = 0; i < best; i++){
		cnt += A[curInd--] * (x + y) / 100;
	}
	for(int i = 0; i < _a; i++){
		cnt += A[curInd--] * x / 100;
	}
	for(int i = 0; i < _b; i++){
		cnt += A[curInd--] * y / 100;
	}
	return cnt >= t;
}

void sub(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	cin >> x >> a >> y >> b;
	if(x < y){
		swap(x, y);
		swap(a, b);
	}
	ll t;
	cin >> t;
	int upper = n + 1;
	int lower = 1;
	while(upper != lower){
		int mid = (upper + lower) / 2;
		if(test(t, mid)){
			upper = mid;
		}else{
			lower = mid + 1;
		}
	}
	if(upper == n + 1){
		cout << -1 << endl;
	}else{
		cout << lower << endl;
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}