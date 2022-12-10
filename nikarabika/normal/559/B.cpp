#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
const LL base = 37, Mod = 10000 * 10000 * 10 + 7;
pie ret;
vector<LL> sh, th;
string s, t;
int n, l;

LL F(LL x){
	return (((((x + 1) % Mod) * x + 1) % Mod) * x + 1) % Mod;
}

void make(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		ret = MP(F(sh[L]), F(th[L]));
		return;
	}
	int mid = (L + R) >> 1;
	pie tret = MP(0, 0);
	make(L, mid, id * 2 + 0);
	tret.L += F(ret.L);
	tret.R += F(ret.R);
	make(mid, R, id * 2 + 1);
	tret.L = (tret.L + F(ret.L)) % Mod;
	tret.R = (tret.R + F(ret.R)) % Mod;
	ret = tret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	l = s.size();
	while(!(l & 1))
		l >>= 1;
	for(int i = 0; i < s.size(); i += l){
		LL shash = 0, thash = 0;	//:-"
		for(int j = i; j < i + l; j++){
			shash = (shash * base + s[j]) % Mod;
			thash = (thash * base + t[j]) % Mod;
		}
		sh.PB(shash);
		th.PB(thash);
	}
	n = sh.size();
	make();
	cout << ((ret.L == ret.R) ? "YES" : "NO") << endl;
	return 0;
}