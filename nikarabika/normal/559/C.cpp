#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 3e5 + 85 - 69;
const LL Mod = 10000 * 10000 * 10 + 7;
LL fact[maxn], revfact[maxn], dp[maxn];
vector<pie> bl;
LL h, w, n;

LL C(LL n, LL r){
	LL makh = (revfact[r] * revfact[n - r]) % Mod;
	return (fact[n] * makh) % Mod;
}

pie get(LL a, LL b){
	if(b == 0)
		return MP(1, 0);
	pie an = get(b, a % b);
	return MP(an.R, an.L - (a / b) * an.R);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		bl.PB(MP(fi, se));
	}
	sort(bl.begin(), bl.end());
	if(bl[0] == MP(1LL, 1LL) or bl.back() == MP(h, w)){
		cout << 0 << endl;
		return 0;
	}
	fact[0] = 1;
	revfact[0] = 1;
	for(LL i = 1; i < 250000; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		revfact[i] = ((get(fact[i], Mod).L % Mod) + Mod) % Mod;
	}
	for(int i = bl.size() - 1; i >= 0; i--){
		dp[i] = C(h - bl[i].L + w - bl[i].R, h - bl[i].L);
		for(int j = i + 1; j < bl.size(); j++)
			dp[i] = (dp[i] - ((C(bl[j].L + bl[j].R - bl[i].L - bl[i].R, bl[j].L - bl[i].L) * dp[j]) % Mod)) % Mod;
		if(dp[i] < 0)
			dp[i] += Mod;
	}
	LL ans = C(h + w - 2, h - 1);
	for(int i = 0; i < bl.size(); i++)
		ans = (ans - ((C(bl[i].L + bl[i].R - 2, bl[i].L - 1) * dp[i]) % Mod)) % Mod;
	cout << (ans + Mod) % Mod << endl;
	return 0;
}