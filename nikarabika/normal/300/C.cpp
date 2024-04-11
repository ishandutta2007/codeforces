#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e6 + 85 - 69;
const LL D = 1e9 + 7;
LL a, b, n;
LL ans, comb[maxn];

bool isgood(LL x){
	while(x > 0){
		int d = x % 10;
		if(d != a and d != b)
			return false;
		x /= 10;
	}
	return true;
}

LL Pow(LL x, LL y){
	if(y == 0) return 1;
	if(y == 1) return x;
	LL t = Pow(x, y / 2);
	return (((t * t) % D) * Pow(x, y & 1)) % D;
}

LL Div(LL x, LL y){
	return (x * Pow(y, D - 2)) % D;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> n;
	comb[0] = 1;
	for(LL cb = 0; cb <= n; cb++){
		LL sum = b * cb + a * (n - cb);
		if(isgood(sum))
			ans = (ans + comb[cb]) % D;
		if(cb < n / 2 + 2){
			comb[cb + 1] = (comb[cb] * (n - cb)) % D;
			comb[cb + 1] = Div(comb[cb + 1], cb + 1);
		}
		else
			comb[cb + 1] = comb[n - cb - 1];
	}
	cout << ans << endl;
	return 0;
}