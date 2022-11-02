#include <bits/stdc++.h>
#define ll long long
using namespace std;
int C[100000];
int A[100000], B[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i < n; i++){
		cin >> A[i];
		A[i]--;
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
		B[i]--;
		C[B[i]] = i;
	}
	int curPos = -1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int v = A[i];
		int pos = C[v];
		if(pos > curPos){
			ans += pos - curPos - 1;
			curPos = pos;
		}
	}
	cout << ans;
	return 0;
}