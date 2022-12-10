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
#define next nexT

const int maxn = 100 * 1000 + 85 - 69;
int sa[maxn],
	pos[maxn],
	tmp[maxn],
	lcp[maxn],
	last[maxn],
	next[maxn],
	next2[maxn],
	gap;
LL ans;
string s;
stack<int> stc;

bool sufCmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < sz(s) and j < sz(s)) ? pos[i] < pos[j] : i > j;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < sz(s); i++)
		sa[i] = i, pos[i] = s[i];
	for(gap=1;;gap<<=1){
		sort(sa, sa + sz(s), sufCmp);
		for(int i = 0; i + 1 < sz(s); i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < sz(s); i++) pos[sa[i]] = tmp[i];
		if(tmp[sz(s) - 1] == sz(s) - 1) break;
	}
	int match = 0;
	for(int i = 0; i < sz(s); i++){
		if(match) match--;
		if(!pos[i]) continue;
		int cur = i, pre = sa[pos[i] - 1];
		while(max(pre, cur) + match < sz(s) and s[pre + match] == s[cur + match]) match++;
		lcp[pos[i]] = match;
	}
	for(int i = 0; i < sz(s); i++){
		while(sz(stc) and lcp[stc.top()] >= lcp[i]) stc.pop();
		last[i] = (sz(stc) ? stc.top() : 0);
		stc.push(i);
	}
	while(sz(stc)) stc.pop();
	for(int i = sz(s) - 1; i >= 0; i--){
		while(sz(stc) and lcp[stc.top()] >= lcp[i]) stc.pop();
		next[i] = (sz(stc) ? stc.top() : sz(s));
		stc.push(i);
	}
	while(sz(stc)) stc.pop();
	for(int i = sz(s) - 1; i >= 0; i--){
		while(sz(stc) and lcp[stc.top()] > lcp[i]) stc.pop();
		next2[i] = (sz(stc) ? stc.top() : sz(s));
		stc.push(i);
	}
	for(int i = 0; i < sz(s); i++) if(lcp[i] and lcp[next2[i]] != lcp[i]){
		LL parh = max(lcp[last[i]], lcp[next[i]]);
		LL dcnt = next[i] - last[i];
		ans += dcnt * (dcnt + 1) / 2 * (lcp[i] - parh);
	}
	for(int i = 0; i < sz(s); i++){
		int an = max(lcp[i], lcp[i + 1]);
		if(an < sz(s) - sa[i])
			ans += sz(s) - sa[i] - an;
	}
	cout << ans << endl;
	return 0;
}