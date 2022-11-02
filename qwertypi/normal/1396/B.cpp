#include <bits/stdc++.h>

#define int long long

using namespace std;

int A[101];
int s[101];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	sort(A, A + n, [](int a, int b){
		return a > b;
	});
	
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
	}
	
	if(A[0] > s[n] - s[1]){
		cout << "T" << endl;
		return;
	}else{
		cout << ((s[n] % 2) ? "T" : "HL") << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}