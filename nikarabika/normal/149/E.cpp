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
#define next Next

const int maxn = 1e5 + 85 - 69;
int next[maxn], left_match[maxn], right_match[maxn];
string s, t;

bool solve(void){
	if(sz(t) == 1)
		return 0;
	int match = 0;
	for(int i = 1; i < sz(t); i++){
		while(match > 0 and t[i] != t[match])
			match = next[match - 1];
		match += t[i] == t[match];
		next[i] = match;
	}
	match = 0;
	for(int i = 0; i < sz(s); i++){
		while(match > 0 and s[i] != t[match])
			match = next[match - 1];
		match += s[i] == t[match];
		left_match[i] = (i == 0 ? match : max(left_match[i - 1], match));
		if(match == sz(t))
			match = next[match - 1];
	}
	reverse(all(s));
	reverse(all(t));
	match = 0;
	for(int i = 1; i < sz(t); i++){
		while(match > 0 and t[i] != t[match])
			match = next[match - 1];
		match += t[i] == t[match];
		next[i] = match;
	}
	match = 0;
	for(int i = 0; i < sz(s); i++){
		while(match > 0 and s[i] != t[match])
			match = next[match - 1];
		match += s[i] == t[match];
		right_match[i] = match;
		if(match == sz(t))
			match = next[match - 1];
	}
	reverse(all(s));
	reverse(right_match, right_match + sz(s));
	for(int i = 0; i + 1 < sz(s); i++)
		if(left_match[i] + right_match[i + 1] >= sz(t))
			return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n, ans = 0;
	cin >> n;
	while(n--){
		cin >> t;
		ans += solve();
	}
	cout << ans;
	return 0;
}