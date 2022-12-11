#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int AL = 26;
const int N = (int)1e6 + 9;

int powr(int n, int k){
	if(k == 0)
		return 1;
	int v = powr(n, k / 2);
	v = (v * 1ll * v) % MOD;
	if(k&1)
		v = (v * 1ll * n) % MOD;
	return v;
}

int cnt[AL];
int f[N];
int inv[N];

int C(int a, int b){
	if(b == 0)
		return 1;
	int v = f[a];
	v = (v * 1ll * inv[b]) % MOD;
	v = (v * 1ll * inv[a - b]) % MOD;
	return v;
}

int ways(string a, string b){
	for(int j = 0 ; j < AL; j ++ )
		cnt[j] = 0;
	for(auto x : a){
		cnt[x - 'a'] ++ ;
	}
	
	int answ =0 ;
	int mlt;
	int sz = a.size();
	int nsz;
	int y; 
	bool ok;
	for(int i = 0 ; i < b.size(); i ++ ){
		nsz = sz - 1;
		y = b[i] - 'a';
		ok = false;
		for(int t = 0; t < y; t ++ ){
			if(cnt[t] > 0)
				ok = true;
		}
		if(ok){
			mlt = 1;
			for(int r = AL - 1; r >= 0;r -- ){
				mlt = (mlt * 1ll * C(nsz, cnt[r])) % MOD;
				nsz -= cnt[r];
				nsz += (r == y);
			}
			answ = (answ + mlt) % MOD;
		}
		cnt[b[i] - 'a'] -- ;
		if(cnt[b[i] - 'a'] < 0)
			break;
		sz -- ;
	}
	return answ;
}

int main(){
	fastIO;
	f[0] = 1;
	inv[0] = 1;
	for(int i = 1; i < N; i ++ ){
		f[i] = (1ll * i * f[i - 1]) % MOD;
		inv[i] = powr(f[i], MOD - 2);
	}
	string a, b;
	cin >> a >> b;
	cout << (ways(a, b) - ways(a, a) + MOD - 1) % MOD << "\n";
	return 0;
}