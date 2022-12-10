//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
#define func(x) (x == '(' ? +1 : -1)

const int maxn = 2000 * 1000 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7,
	  base = 313;
int ans[maxn],
	sum[maxn],
	kamed;
LL hsh[maxn],
   P[maxn];
string s;
vector<int> possib;

void build(void){
	sum[0] = func(s[0]);
	for(int i = 1; i < sz(s); i++)
		sum[i] = sum[i - 1] + func(s[i]);
	deque<int> dq;
	int n = sz(s) / 2;
	for(int i = 0; i < sz(s); i++){
		if(sz(dq) and dq.back() <= i - n) dq.pop_back();
		while(sz(dq) and sum[dq.front()] >= sum[i])
			dq.pop_front();
		dq.push_front(i);
		if(i - n + 1 >= 0) ans[i - n + 1] = sum[dq.back()];
	}
	return;
}

LL H(int st, int en){
	return st == 0 ? hsh[en] : (((hsh[en] - hsh[st - 1] * P[en - st + 1]) % Mod) + Mod) % Mod;
}

void build_hash(void){
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	hsh[0] = s[0];
	for(int i = 1; i < sz(s); i++)
		hsh[i] = (hsh[i - 1] * base + s[i]) % Mod;
	return;
}

bool sufCmp(int i, int j){
	int lo = 0, hi = sz(s) / 2;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(H(i, i + mid - 1) == H(j, j + mid - 1))
			lo = mid;
		else
			hi = mid;
	}
	if(hi == sz(s) / 2)
		return false;
	return s[i + lo] < s[j + lo];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	possib.reserve(1 << 20);
	s.reserve(1 << 21);
	cin >> s;
	s += s;
	build_hash();
	build();
	int Min = 1000000 * 100;
	for(int i = 0; i < sz(s) / 2; i++){
		int val = max(-(ans[i] - kamed), 0);
		if(val < Min)
			possib.clear(), Min = val;
		if(val == Min)
			possib.PB(i);
		kamed += func(s[i]);
	}
	int id = possib[0];
	for(auto idx : possib)
		if(sufCmp(idx, id))
			id = idx;
	int op = 0;//, id = -1;
	//for(int i = 0; i < sz(s); i++) if(mark[sa[i]]) {id = i; break;}
	for(int i = 0; i < sz(s) / 2; i++) op += (s[i] == '(');
	for(int i = 0; i < Min; i++) cout << '(';
	for(int i = 0; i < sz(s) / 2; i++) cout << s[i + id];
	for(int i = 0; i < op + Min - (sz(s) / 2 - op); i++) cout << ')';
	return 0;
}