#include <bits/stdc++.h>

using namespace std;

int A[200000];

int n;
int rec(int l = 0, int r = n - 1, int lv = 29){
	// cout << l << ' ' << r << ' ' << lv << endl;
	if(l == r) return 0;
	int L = l, R = r;
	for(int i = l; i <= r; i++){
		if(A[L] & (1 << lv)){
			swap(A[L], A[R--]);
		}else{
			L++;
		}
	}
	int cnt_0 = L - l;
	int cnt_1 = r - l + 1 - cnt_0;
	if(cnt_0 == 0) return rec(L, r, lv - 1);
	if(cnt_1 == 0) return rec(l, L - 1, lv - 1);
	return min(cnt_0 - 1 + rec(L, r, lv - 1), cnt_1 - 1 + rec(l, L - 1, lv - 1));
}

int32_t main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cout << rec() << endl;
}