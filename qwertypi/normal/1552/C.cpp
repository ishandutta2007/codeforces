#include <bits/stdc++.h>

using namespace std;

int A[100][2];

bool used[200];

bool inter(int i, int j){
	bool side1 = A[i][0] <= A[j][0] && A[j][0] <= A[i][1];
	bool side2 = A[i][0] <= A[j][1] && A[j][1] <= A[i][1];
	if(side1 ^ side2){
		return true;
	}else{
		return false;
	}
}

void prun(int x, int y){
	if(inter(x, y)) return;
	swap(A[x][0], A[y][0]);
	if(inter(x, y)) return;
	swap(A[x][0], A[y][0]);
	swap(A[x][0], A[y][1]);
	return;
}

void sub(){
	int n, k;
	cin >> n >> k;
	fill(used, used + n * 2, 0);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < 2; j++){
			cin >> A[i][j];
			A[i][j]--;
			used[A[i][j]] = true;
		}
		if(A[i][0] > A[i][1]) swap(A[i][0], A[i][1]);
	}
	
	vector<int> vi;
	for(int i = 0; i < n * 2; i++){
		if(!used[i]){
			vi.push_back(i);
		}
	}
	for(int i = 0; i < n - k; i++){
		A[k + i][0] = vi[i * 2], A[k + i][1] = vi[i * 2 + 1];
	}
	
	for(int i = 0; i < n; i++){
		for(int x = k; x < n; x++){
			for(int y = k; y < n; y++){
				if(x != y) prun(x, y);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ans += inter(i, j);
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}