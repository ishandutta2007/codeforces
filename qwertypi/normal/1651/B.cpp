#include <bits/stdc++.h>

using namespace std;

int A[10001];
void sub(){
	int n;
	cin >> n;
	if(n <= 19){
		cout << "YES" << endl;
		int v = 1;
		for(int i = 0; i < n; i++){
			cout << v << ' '; v *= 3;
		}
	cout << endl;
	}else{
		cout << "NO" << endl;
	}
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		sub();
	}
}