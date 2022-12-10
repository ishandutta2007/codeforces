#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL a;
	cin >> a;
	LL ans = 1;
	for(LL i = 1; i < a; i++)
		ans += i * 12;
	cout << ans << endl;
	return 0;
}