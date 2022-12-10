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
#define hash Hash

const int maxn = 2e5 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7,
	  base = 313;
LL hash[maxn],
   P[maxn],
   scnt[maxn],
   tcnt[maxn],
   n, m;
char sc[maxn],
	 tc[maxn];

LL NumHash(LL x){
	return (x * x * x + 5 * x * x + 4 * x + 83) % Mod;
}

LL GetHash(int st, int en){
	return st == 0 ? hash[en] : (((hash[en] - hash[st - 1] * P[en - st + 1]) % Mod) + Mod) % Mod;
}

bool isok(int sid, int tid){
	return sc[sid] == tc[tid] and tcnt[tid] <= scnt[sid];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> scnt[i] >> sc[i] >> sc[i];
		if(i and sc[i] == sc[i - 1]){
			scnt[i - 1] += scnt[i];
			i--, n--;
		}
	}
	for(int i = 0; i < m; i++){
		cin >> tcnt[i] >> tc[i] >> tc[i];
		if(i and tc[i] == tc[i - 1]){
			tcnt[i - 1] += tcnt[i];
			i--, m--;
		}
	}
	if(m == 1){
		LL ans = 0;
		for(int i = 0; i < n; i++)
			ans += (sc[i] == tc[0]) * max(0LL, scnt[i] - tcnt[0] + 1);
		cout << ans << '\n';
		return 0;
	}
	/*if(m == 2){
		int ans = 0;
		for(int i = 0; i + 1 < n; i++)
			ans += (sc[i] == tc[0] and sc[i + 1] == tc[1] and scnt[i] <= tcnt[0] and scnt[i + 1] <= tcnt[1]);
		cout << ans << endl;
		return 0;
	}*/
	LL thash = 0;
	for(int i = 1; i + 1 < m; i++)
		thash = (thash * base + tc[i] * NumHash(tcnt[i])) % Mod;
	hash[0] = (sc[0] * NumHash(scnt[0])) % Mod;
	for(int i = 1; i < n; i++)
		hash[i] = (hash[i - 1] * base + sc[i] * NumHash(scnt[i])) % Mod;
	LL ans = 0;
	for(int i = 0; i + m <= n; i++)
		if(GetHash(i + 1, i + m - 2) == thash and isok(i, 0) and isok(i + m - 1, m - 1))
			ans++;
	cout << ans << endl;
	return 0;
}