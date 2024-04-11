#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001], B[200001];
int Ap[200001], Bp[200001];

int n;

int d(int i, int j){
	if(i < 0 || j < 0) return (1LL << 60);
	return abs(Ap[i] - Bp[j]);
}

void sub(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		Ap[i] = A[i];
	}
	int a0, a1, b0, b1;
	vector<pair<int, int>> a;
	for(int i = 0; i < n; i++){
		a.push_back({A[i], i});
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		if(a[i].second == 0) a0 = i;
		if(a[i].second == n - 1) a1 = i;
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
		Bp[i] = B[i];
	}
	vector<pair<int, int>> b;
	for(int i = 0; i < n; i++){
		b.push_back({B[i], i});
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < n; i++){
		if(b[i].second == 0) b0 = i;
		if(b[i].second == n - 1) b1 = i;
	}
	sort(Ap, Ap + n);
	sort(Bp, Bp + n);
	int ans = 1LL << 60;
	int idx_1 = lower_bound(Bp, Bp + n, A[0]) - Bp;
	int idx_2 = lower_bound(Bp, Bp + n, A[n - 1]) - Bp;	
	int idx_3 = lower_bound(Ap, Ap + n, B[0]) - Ap;
	int idx_4 = lower_bound(Ap, Ap + n, B[n - 1]) - Ap;
	ans = min(ans, min(d(a0, idx_1), d(a0, idx_1 - 1)) + min(d(a1, idx_2), d(a1, idx_2 - 1)) + min(d(idx_3, b0), d(idx_3 - 1, b0)) + min(d(idx_4, b1), d(idx_4 - 1, b1)));
	ans = min(ans, min(d(a0, idx_1), d(a0, idx_1 - 1)) + min(d(idx_3, b0), d(idx_3 - 1, b0)) + d(a1, b1));
	ans = min(ans, min(d(a0, idx_1), d(a0, idx_1 - 1)) + min(d(idx_4, b1), d(idx_4 - 1, b1)) + d(a1, b0));
	ans = min(ans, min(d(a1, idx_2), d(a1, idx_2 - 1)) + min(d(idx_3, b0), d(idx_3 - 1, b0)) + d(a0, b1));
	ans = min(ans, min(d(a1, idx_2), d(a1, idx_2 - 1)) + min(d(idx_4, b1), d(idx_4 - 1, b1)) + d(a0, b0));
	ans = min(ans, d(a0, b0) + d(a1, b1));
	ans = min(ans, d(a0, b1) + d(a1, b0));
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		sub();
	}
}