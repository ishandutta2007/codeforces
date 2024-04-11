#include <bits/stdc++.h>

using namespace std;
#define int long long

int A[100000];
int cnt[100000];
set<pair<int, int>> S; // -cost, index

int f(int x, int y){
	if(x < y) return (1LL << 60);
	return (x % y) * (x / y + 1) * (x / y + 1) + (y - x % y) * (x / y) * (x / y);
}

int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		cnt[i] = 1;
		S.insert({f(A[i], 2) - f(A[i], 1), i});
	}
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += A[i] * A[i];
	}
	
	for(int i = 0; i < k - n; i++){
		pair<int, int> sos = *S.begin();
		S.erase(*S.begin());
		sum += sos.first;
		cnt[sos.second]++;
		S.insert({f(A[sos.second], cnt[sos.second] + 1) - f(A[sos.second], cnt[sos.second]), sos.second});
	}
	
	cout << sum << endl;
}