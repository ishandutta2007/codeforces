#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 1e5 + 10;
int nexxt[maxn], lasst[maxn];
bool hast[maxn];
ll dp[maxn], sum[maxn], Mod = 1e9 + 7;
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	int match = 0;
	for(int i = 1; i < t.size(); i++){
		while(match > 0 and t[match] != t[i])
			match = nexxt[match - 1];
		if(t[match] == t[i])
			match++;
		nexxt[i] = match;
	}
	match = 0;
	memset(lasst, -1, sizeof lasst);
	for(int i = 0; i < s.size(); i++){
		while(match > 0 and s[i] != t[match])
			match = nexxt[match - 1];
		if(s[i] == t[match])
			match++;
		if(match == t.size())
			lasst[i] = i - t.size() + 1, match = nexxt[match - 1];
		else if(i != 0)
			lasst[i] = lasst[i - 1];
	}
	sum[0] = 1;
	for(int i = 0; i < s.size(); i++){
		if(lasst[i] != -1)
			dp[i] = ((i != 0 ? dp[i - 1] : 0) + sum[lasst[i]]) % Mod;
		else
			dp[i] = 0;
		sum[i + 1] = (sum[i] + dp[i] + 1) % Mod;
	}
	cout << dp[s.size() - 1] << endl;
	return 0;
}