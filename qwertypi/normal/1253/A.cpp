#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[200000], B[200000];

void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int j = 0; j < n; j++){
		cin >> B[j];
	}
	int _st = 1000000, _end = -1;
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			_st = min(_st, i);
			_end = max(_end, i);
		}
	}
	if(_end == -1){
		cout << "YES" << endl;
		return;
	}
	if(A[_st] > B[_st]){
		cout << "NO" << endl;
		return;
	}
	int diff = A[_st] - B[_st];
	for(int i = _st; i <= _end; i++){
		A[i] -= diff;
	}
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}