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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#undef next
#define next NeXt

const int maxn = 2500;
int dparr[maxn], next[maxn];
pii dpstr[maxn];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(dpstr, dpstr + maxn, MP(-1, -1));
	cin >> s >> t;
	for(int st = 0; st < sz(s); st++){
		int match = 0;
		memset(next, 0, sizeof next);
		for(int i = st + 1; i < sz(s); i++){
			while(match > 0 and s[i] != s[match + st])
				match = next[match - 1];
			match += s[i] == s[match + st];
			next[i - st] = match;
		}
		match = 0;
		for(int i = 0; i < sz(t); i++){
			while(match > 0 and t[i] != s[match + st])
				match = next[match - 1];
			match += t[i] == s[match + st];
			if(match > abs(dpstr[i].L - dpstr[i].R))
				dpstr[i] = MP(st, st + match - 1);
			if(match == sz(s))
				match = next[match - 1];
		}
	}
	reverse(s.begin(), s.end());
	for(int st = 0; st < sz(s); st++){
		int match = 0;
		memset(next, 0, sizeof next);
		for(int i = st + 1; i < sz(s); i++){
			while(match > 0 and s[i] != s[match + st])
				match = next[match - 1];
			match += s[i] == s[match + st];
			next[i - st] = match;
		}
		match = 0;
		for(int i = 0; i < sz(t); i++){
			while(match > 0 and t[i] != s[match + st])
				match = next[match - 1];
			match += t[i] == s[match + st];
			if(match > abs(dpstr[i].L - dpstr[i].R))
				dpstr[i] = MP(sz(s) - st - 1, sz(s) - (st + match - 1) - 1);
			if(match == sz(s))
				match = next[match - 1];
		}
	}
	int *dp = dparr + 1;
	memset(dparr, 63, sizeof dparr);
	dp[-1] = 0;
	for(int i = 0; i < sz(t); i++){
		int len = abs(dpstr[i].R - dpstr[i].L) + 1;
		if(dpstr[i].L == -1)
			continue;
		smin(dp[i], dp[i - len] + 1);
	}
	int id = sz(t) - 1;
	cout << (dp[id] < maxn ? dp[id] : -1) << '\n';
	if(dp[id] >= maxn)
		return 0;
	vector<pii> ans;
	while(id >= 0){
		ans.PB(MP(dpstr[id].L + 1, dpstr[id].R + 1));
		id -= abs(dpstr[id].L - dpstr[id].R) + 1;
	}
	for(int i = sz(ans) - 1; i >= 0; i--)
		cout << ans[i].L << ' ' << ans[i].R << '\n';
	return 0;
}