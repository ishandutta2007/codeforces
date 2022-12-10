//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;
typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second

const int maxn = 15001;
const LL Mod = 1000000007;
int n, m;
set<pii> s;

void add(int val1, int val2){
	if(s.lower_bound(MP(val1, 0)) == s.end() or s.lower_bound(MP(val1, 0))->L != val1){
		s.insert(MP(val1, val2));
		return;
	}
	pii x = *s.lower_bound(MP(val1, 0));
	s.erase(s.lower_bound(MP(val1, 0)));
	x.R += val2;
	s.insert(x);
	return;
}

LL Pow(LL x, LL y){
	LL an = x, ret = 1;
	for(int i = 0; i < 32; i++, an = (an * an) % Mod)
		if((y >> i) & 1)
			ret = (ret * an) % Mod;
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

LL C(LL x, LL y){
	y = min(y, x - y);
	LL ret = 1;
	for(LL i = x - y + 1; i <= x; i++){
		ret = (ret * i) % Mod;
		ret = Div(ret, i - x + y);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int div = 2; div * div <= x; div++){
			if(x % div == 0){
				int cnt = 0;
				while(x % div == 0){
					x /= div;
					cnt++;
				}
				add(div, cnt);
			}
		}
		if(x > 1)
			add(x, 1);
	}
	LL ans = 1;
	while(s.size()){
		int x = s.begin() -> R;
		s.erase(s.begin());
		ans = (ans * C(n + x - 1, x)) % Mod;
	}
	cout << ans << endl;
	return 0;
}