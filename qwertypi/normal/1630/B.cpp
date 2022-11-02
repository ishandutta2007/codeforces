#include <bits/stdc++.h>

using namespace std;

int ps[200001];
int A[200001];
int B[200001];
int solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		B[i] = A[i];
	}
	int d = (n + k + 1) / 2;
	int min_dis = (1 << 30), sol[2] = {-1, -1};
	sort(B, B + n);
	for(int i = 0; i <= n - d; i++){
		if(B[i + d - 1] - B[i] < min_dis){
			min_dis = B[i + d - 1] - B[i];
			sol[0] = B[i], sol[1] = B[i + d - 1];
		}
	}
	
	for(int i = 0; i < n; i++){
		ps[i + 1] = ps[i] + (sol[0] <= A[i] && A[i] <= sol[1] ? 1 : -1);
	}
	vector<int> part;
	int idx = 0;
	part.push_back(0);
	for(int i = 1; i < k; i++){
		while(ps[idx] != i && idx <= n) idx++;
		part.push_back(idx);
		idx++;
	}
	part.push_back(n);
	cout << sol[0] << ' ' << sol[1] << endl;
	for(int i = 0; i < (int) part.size() - 1; i++){
		cout << part[i] + 1 << ' ' << part[i + 1] << endl;
	}
	return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}