#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define set unordered_set
#define map unordered_map
using namespace std;

vector<set<int>> ans;
map<int, int> ind;
map<int, set<int>> A;

void sub(){
	int A[3];
	for(int i = 0; i < 3; i++){
		cin >> A[i];
	}
	sort(A, A + 3);
	if(A[0] != A[2]){
		A[0]++;
	}
	if(A[0] != A[2]){
		A[2]--;
	}
	if(A[1] > A[2]){
		A[1]--;
	}else if(A[1] < A[0]){
		A[1]++;
	}
	cout << abs(A[0] - A[1]) + abs(A[2] - A[1]) + abs(A[0] - A[2]) << endl;
}

int32_t main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}