#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100000];
int B[100000];
int C[100000];
void sub(){
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < a; i++){
		cin >> A[i];
		C[A[i] - 1] = i;
	}
	for(int i = 0; i < b; i++){
		cin >> B[i];
		B[i]--;
	}
	int best = -1;
	int ans = 0;
	for(int i = 0; i < b; i++){
		if(C[B[i]] < best){
			ans++;
		}else{
			ans += 1 + (C[B[i]] - i) * 2;
			best = C[B[i]];
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub(); 
	} 
}