#include <bits/stdc++.h>

using namespace std;

int A[200001]; 
int sm[200001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sm[0] = A[0];
	for(int i = 1; i < n; i++){
		sm[i] = min(sm[i - 1], A[i]);
	}
	deque<int> dq;
	for(int i = 0; i < n; i++){
		if(A[i] == sm[i]){
			dq.push_front(A[i]);
		}else{
			dq.push_back(A[i]);
		}
	}
	for(auto elem : dq){
		cout << elem << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}