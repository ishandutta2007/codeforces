//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define hash HASH

const int maxn = 4e6 + 85 - 69;
const LL base = 313,
	  Mod = 1e9 + 9,
	  Mod2 = 1e9 + 7;
map<pll, int> mp;
LL hash[maxn],
   hash2[maxn],
   P[maxn],
   P2[maxn];
bool mark[maxn];
string s;
int n, k, m;

LL H(int st, int en){
	return ((hash[en] - hash[st] * P[en - st]) % Mod + Mod) % Mod;
}

LL H2(int st, int en){
	return ((hash2[en] - hash2[st] * P2[en - st]) % Mod2 + Mod2) % Mod2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	s += s;
	P[0] = 1;
	P2[0] = 1;
	for(int i = 0; i < sz(s); i++){
		P[i + 1] = (P[i] * base) % Mod;
		P2[i + 1] = (P2[i] * base) % Mod2;
		hash[i + 1] = (hash[i] * base + s[i]) % Mod;
		hash2[i + 1] = (hash2[i] * base + s[i]) % Mod2;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		string t;
		cin >> t;
		LL hsh = 0,
		   hsh2 = 0;
		for(auto c : t){
			hsh = (hsh * base + c) % Mod;
			hsh2 = (hsh2 * base + c) % Mod2;
		}
		mp[MP(hsh, hsh2)] = i + 1;
	}
	for(int i = 0; i < k; i++){
		bool can = true;
		for(int j = i; j < n*k + i; j += k){
			int id = mp[MP(H(j, j + k), H2(j, j + k))];
			if(!id or mark[id]){
				can = false;
				break;
			}
			mark[id] = true;
		}
		if(can){
			cout << "YES\n";
			for(int j = i; j < n*k + i; j += k)
				cout << mp[MP(H(j, j + k), H2(j, j + k))] << ' ';
			cout << '\n';
			return 0;
		}
		for(int j = i; j < n*k + i; j += k)
			mark[mp[MP(H(j, j + k), H2(j, j + k))]] = false;
	}
	cout << "NO\n";
	return 0;
}