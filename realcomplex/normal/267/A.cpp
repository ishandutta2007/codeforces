#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	int ans = 0;
	int mod;	
	do{
		if(a<b)swap(a,b);
		ans += a/b;
		mod = a%b;
		a %= b;
	}while(mod!=0);
	cout << ans << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--)solve();
	return 0;
}