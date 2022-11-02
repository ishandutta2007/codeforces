#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int A[200000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	map<int, int> B;
	int ans = 200001;
	for(int i = 0; i < n; i++){
		if(B.find(A[i]) != B.end()){
			ans = min(ans, i - B[A[i]] + 1);
		}
		B[A[i]] = i;
	}
	if(ans == 200001){
		cout << -1 << endl;
		return;
	}else{
		cout << ans << endl;
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}