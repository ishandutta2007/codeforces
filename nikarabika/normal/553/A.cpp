#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL D = 1e9 + 7;
const int maxn = 1e3 + 85 - 69;
LL c[maxn], n, k;

LL Pow(LL x, LL y){
	if(y == 1)
		return x;
	LL t = Pow(x, y / 2);
	t *= t;
	t %= D;
	if(y & 1) t = (t * x) % D;
	return t;
}

LL Div(LL x, LL y){
	return (x * Pow(y, D - 2)) % D;
}

LL C(LL n, LL r){
	LL ans = 1;
	for(LL i = r + 1; i <= n; i++){
		ans = (ans * i) % D;
		ans = Div(ans, i - r);
	}
	return ans;
}

LL solve(LL x, LL y){
	if(x == 0)
		return 1;
	return (C(x - 1, c[y] - 1) * solve(x - c[y], y - 1)) % D;
}

int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> k;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		n += c[i];
	}
	cout << solve(n, k) << endl;
}