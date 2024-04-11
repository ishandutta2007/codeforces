#include <bits/stdc++.h>

using namespace std;

int A[10000];
int _min[10000], _max[10000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		_min[i] = (1 << 30);
	}
	_max[0] = A[0];
	for(int i = 1; i < n; i++){
		_max[i] = max(_max[i - 1], A[i]);
	}
	_min[n - 1] = A[n - 1];
	for(int i = n - 2; i >= 0; i--){
		_min[i] = min(_min[i + 1], A[i]);
	}

	for(int i = 0; i < n; i++){
			if(_max[i] > _min[i]){
		cout << "YES" << endl;
		return;
	}
	}
	cout << "NO" << endl;
} 

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}