#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;
typedef pair<pie, pie> piipii;

#define MP make_pair
#define L first
#define R second

LL n, k, l, m;

piipii MOD(piipii x){
	return MP(MP(x.L.L % m, x.L.R % m), MP(x.R.L % m, x.R.R % m));
}

piipii Pow(LL b){
	if(b == 1)
		return MP(MP(1, 1), MP(1, 0));
	piipii x = Pow(b / 2);
	x = MOD(MP(MP(x.L.L * x.L.L + x.L.R * x.R.L, x.L.L * x.L.R + x.L.R * x.R.R), MP(x.L.L * x.R.L + x.R.L * x.R.R, x.L.R * x.R.L + x.R.R * x.R.R)));
	if(b & 1)
		x = MOD(MP(MP(x.L.L + x.L.R, x.L.L), MP(x.R.L + x.R.R, x.R.L)));
	return x;
}

LL Pow(LL a, LL b){
	if(b == 1)
		return a;
	LL t = Pow(a, b / 2);
	t = (t * t) % m;
	if(b & 1) t = (t * a) % m;
	return t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> l >> m;
	if(l == 0){
		if(k == 0)
			cout << 1 % m << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	if(l == 64){
		if(k > (1ULL << 63) - 1 + (1ULL << 63)){
			cout << 0 << endl;
			return 0;
		}
	}
	else if(l == 63){
		if(k > (1ULL << 62) - 1 + (1ULL << 62)){
			cout << 0 << endl;
			return 0;
		}
	}
	else if(k > (1LL << l) - 1){
		cout << 0 << endl;
		return 0;
	}
	LL sefr = Pow(n + 2).L.R, yek = (((Pow(2, n) - sefr) % m) + m) % m;
	LL ans = 1;
	for(int i = 0; i < l; i++){
		if(k & (1LL << i))
			ans = (ans * yek) % m;
		else
			ans = (ans * sefr) % m;
	}
	cout << ans << endl;
	return 0;
}