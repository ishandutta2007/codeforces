#include <bits/stdc++.h>

using namespace std;

int sub(){
	int a, b, n;
	cin >> a >> b >> n;
	int cnt = 0;
	while(a <= n && b <= n){
		if(a < b) swap(a, b);
		b += a;
		cnt++;
	}
	cout << cnt << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}