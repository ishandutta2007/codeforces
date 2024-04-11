//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000 + 1,
	  maxsq = 500;
const LL Mod = 1000 * 1000 * 1000 + 7;
int sum[maxsq][maxn];
LL makoos[maxn],
   P[maxn];
int n,
	num[maxn],
	ty[maxn];
vector<int> all;

LL Pow(LL x, LL y){
	LL ret = 1,
	   an = x;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++){
		makoos[i] = Div(1, i);
		P[i] = (P[i - 1] * 26) % Mod;
	}
	string str;
	cin >> n
		>> str;
	int lastnum = sz(str);
	all.PB(lastnum);
	for(int i = 0; i < n; i++){
		cin >> ty[i];
		if(ty[i] == 1){
			cin >> str;
			num[i] = sz(str);
			all.PB(num[i]);
		}
		else
			cin >> num[i];
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < sz(all); i++){
		LL val = Div(1, P[all[i]]);
		for(int j = all[i]; j < maxn; j++){
			sum[i][j] = (sum[i][j - 1] + val) % Mod;
			val = (val * 25 * j) % Mod;
			val = (val * makoos[26]) % Mod;
			val = (val * makoos[j - all[i] + 1]) % Mod;
		}
	}
	lastnum = lower_bound(all(all), lastnum) - all.begin();
	for(int i = 0; i < n; i++){
		if(ty[i] == 1)
			lastnum = lower_bound(all(all), num[i]) - all.begin();
		else
			cout << (1LL * sum[lastnum][num[i]] * P[num[i]]) % Mod << '\n';
	}
	return 0;
}