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

const int maxn = 1e5 + 85 - 69,
	  maxl = 62;
LL a[maxn],
   num[maxl],
   vec[maxl],
   n, sz;
bitset<maxn> com[maxl];

int get_left(LL val){
	for(int i = maxl - 1; ~i; --i)
		if((val >> i) & 1LL)
			return i;
	return 85;
}

void add(int id){
	LL val = a[id];
	sz = 0;
	for(int i = maxl - 1; i >= 0; i--) if(~num[i])
		if((val >> i) & 1LL)
			val ^= num[i], vec[sz++] = i;
	if(!val) return;
	int bid = get_left(val);
	num[bid] = val;
	for(int i = 0; i < sz; i++){
		int ii = vec[i];
		com[bid] ^= com[ii];
	}
	com[bid][id] = 1;
	for(int i = 0; i < maxl; i++) if(~num[i] and i != bid)
		if((num[i] >> bid) & 1LL)
			num[i] ^= num[bid], com[i] ^= com[bid];
	return;
}

LL func(LL val, LL xs){
	LL ret = 0;
	for(int i = maxl - 1; i >= 0; i--)
		if(!((xs >> i) & 1LL))
			ret = (ret << 1) | ((val >> i) & 1LL);
	for(int i = maxl - 1; i >= 0; i--)
		if((xs >> i) & 1LL)
			ret = (ret << 1) | ((val >> i) & 1LL);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(num, -1, sizeof num);
	cin >> n;
	LL xsum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		xsum ^= a[i];
	}
	for(int i = 0; i < n; i++)
		a[i] = func(a[i], xsum);
	for(int i = 0; i < n; i++)
		add(i);
	for(int i = 0; i < n; i++){
		bool an = false;
		for(int j = 0; j < maxl; j++)
			an ^= com[j][i];
		cout << 1 + an << ' ';
	}
	cout << '\n';
	return 0;
}