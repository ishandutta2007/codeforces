#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int A[100000];
 
void _ans(int k){
	cout << "finish " << k << endl;
	return;
}
 
int _or(int i, int j){
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	int ver;
	cin >> ver;
	return ver;
}
 
int _and(int i, int j){
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	int ver;
	cin >> ver;
	return ver;
}
 
int _sum(int i, int j){
	int res = _or(i, j) + _and(i, j);
	return res;
}
 
int other(int i, int j){
	if(i != 0 && j != 0) return 0;
	if(i != 1 && j != 1) return 1;
	return 2; 
}
int C[100000];
int32_t main(){
	int n, k;
	cin >> n >> k;
	k--;
	for(int i = 1; i < n; i++){
		A[i] = _sum(0, i);
	}
	vector<pair<int, int>> B;
	A[0] = _sum(1, 2);
	C[0] = (A[0] + A[1] + A[2]) / 2 - A[0];
	for(int i = 1; i < n; i++){
		C[i] = A[i] - C[0];
	}
	for(int i = 0; i < n; i++){
		B.push_back({C[i], i});
	}
	sort(B.begin(), B.end());
	_ans(B[k].first);
}