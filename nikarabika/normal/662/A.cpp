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

const int maxn = 5e5 + 85 - 69,
	  maxl = 62;
const LL Mod = 1000001;
LL a[maxn];
LL valu;
int n;
int Log[Mod];

void build_Log(void){
	memset(Log, -1, sizeof Log);
	LL val = 1;
	for(int i = 0; i < maxl; i++){
		if(~Log[val])
			assert(0);
		Log[val] = i;
		val += val;
		if(val >= Mod)
			val -= Mod;
	}
	return;
}

int rightmost(LL x){
	return Log[(x & -x) % Mod];
}

struct ABOO{
	LL arr[maxn];
	LL base[maxl];
	int basecnt;
	ABOO(){
		memset(base, -1, sizeof base);
	}
	void build_base(int id = 0){
		if(id == n)
			return;
		for(int i = 0; i < maxl; i++)
			if(((arr[id] >> i) & 1LL) and ~base[i])
				arr[id] ^= base[i];
		if(arr[id]){
			int x = rightmost(arr[id]);
			for(int i = 0; i < maxl; i++)
				if(base[i] != -1LL and ((base[i] >> x) & 1LL))
					base[i] ^= arr[id];
			basecnt++;
			base[x] = arr[id];
		}
		build_base(id + 1);
	}
	bool can_generate(LL x){
		for(int i = 0; x and i < maxl; i++)
			if(((x >> i) & 1LL) and base[i] != -1LL)
				x ^= base[i];
		return x ? false : true;
	}
	LL &operator[](int i){
		return arr[i];
	}
} b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build_Log();
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		valu ^= a[i];
		b[i] ^= a[i];
	}
	b.build_base();
	if(!b.can_generate(valu))
		cout << "1/1";
	else
		cout << (1LL << b.basecnt) - 1 << "/" << (1LL << b.basecnt);
	return 0;
}