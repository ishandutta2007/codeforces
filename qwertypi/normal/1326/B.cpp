#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[200000];

int curMax = 0;
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		cout << curMax + A[i] << ' ';
		curMax = max(curMax, curMax + A[i]);
	}
}