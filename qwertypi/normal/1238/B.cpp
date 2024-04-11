#include <bits/stdc++.h>
 
using namespace std;
 
int A[100000];
set<int> B;
void sub(){
	B.clear();
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		B.insert(A[i]);
	}
	int i = 0;
	for(auto j : B){
		A[i++] = j; 
	}
	int curMax = A[i - 1];
	int curInd = i - 1;
	int res = 0;
	while(curInd != -1 && curMax > 0){
		curMax = A[--curInd] - (res + 1) * k;
		res++;
	}
	cout << res << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}