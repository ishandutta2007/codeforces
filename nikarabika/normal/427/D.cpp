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

const int maxn = 10000 + 10;
int sa[maxn],
	lcp[maxn],
	pos[maxn],
	tmp[maxn],
	gap;
string s1, s2, s;

bool sufCmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < sz(s) and j < sz(s)) ? pos[i] < pos[j] : i > j;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;
	s = s1 + '{' + s2 + '}';
	for(int i = 0; i < sz(s); i++)
		sa[i] = i, pos[i] = s[i];
	for(gap = 1; ; gap <<= 1){
		sort(sa, sa + sz(s), sufCmp);
		for(int i = 0; i + 1 < sz(s); i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < sz(s); i++) pos[sa[i]] = tmp[i];
		if(tmp[sz(s) - 1] == sz(s) - 1) break;
	}
	int match = 0;
	for(int i = 0; i + 1 < sz(s); i++){
		if(match) match--;
		if(!pos[i]) continue;
		int cur = i, pre = sa[pos[i] - 1];
		while(s[cur + match] == s[pre + match]) match++;
		lcp[pos[i]] = match;
	}
	int ans = 1e5;
	for(int i = 0; i < sz(s); i++)
		if(lcp[i] and max(lcp[i - 1], lcp[i + 1]) < lcp[i] and (sa[i] < sz(s1) xor sa[i - 1] < sz(s1)))
			smin(ans, max(lcp[i - 1], lcp[i + 1]) + 1);
	cout << (ans == 1e5 ? -1 : ans) << '\n';
	return 0;
}