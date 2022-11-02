#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n;
	cin >> n;
	cout << (1LL << n) - 1 << endl;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		sub();
	}
}