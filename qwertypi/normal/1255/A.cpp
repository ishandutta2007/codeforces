#include <bits/stdc++.h>

using namespace std;
void sub(){
	int l, r;
	cin >> l >> r;
	if(l > r){
		swap(l, r);
	}
	int ans = 0;
	ans += (r - l) / 5;
	int diff = (r - l) % 5;
	ans += diff / 2;
	ans += diff % 2;
	cout << ans << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}