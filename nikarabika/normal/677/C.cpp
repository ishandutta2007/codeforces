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

const LL Mod = 1e9 + 7;
LL cnt[64];

int mp(char c){
	if(c >= '0' and c <= '9')
		return c - '0' + 0;
	if(c >= 'A' and c <= 'Z')
		return c - 'A' + 10;
	if(c >= 'a' and c <= 'z')
		return c - 'a' + 36;
	if(c == '-')
		return 62;
	return 63;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 64; i++)
		for(int j = 0; j < 64; j++)
			cnt[i & j]++;
	LL ans = 1;
	string s;
	cin >> s;
	for(int i = 0; i < sz(s); i++)
		ans = (ans * cnt[mp(s[i])]) % Mod;
	cout << ans << endl;
	return 0;
}