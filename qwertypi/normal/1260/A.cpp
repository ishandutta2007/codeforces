#include <bits/stdc++.h>

using namespace std;

void sub(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 0; i < a; i++){
		ans += ((b / a) + (i < b % a)) * ((b / a) + (i < b % a));
	}
	cout << ans << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}