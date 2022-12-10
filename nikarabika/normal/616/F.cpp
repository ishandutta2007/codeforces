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

const int maxn = 1000 * 1000;
int sa[maxn],
	pos[maxn],
	tmp[maxn],
	siz[maxn],
	next[maxn],
	last[maxn],
	tpos[maxn],
	gap, n;
LL lcp[maxn],
   sum[maxn],
   cost[maxn],
   ans;
stack<int> stc;
vector<int> s;

bool sufCmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < sz(s) and j < sz(s)) ? pos[i] < pos[j] : i > j;
}

void build_partisum(void){
	int ptr = 0;
	for(int i = 0; i < n; i++){
		tpos[i] = pos[ptr];
		for(int j = 0; j < siz[i]; j++, ptr++)
			sum[pos[ptr]] = cost[i];
		ptr++;
	}
	for(int i = 1; i <= sz(s); i++)
		sum[i] += sum[i - 1];
	return;
}

LL get(int st, int en){
	return (st) ? sum[en] - sum[st - 1] : sum[en];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		siz[i] = sz(t);
		for(int j = 0; j < sz(t); j++)
			s.PB(t[j]);
		s.PB(500 + i);
	}
	for(int i = 0; i < n; i++) cin >> cost[i];
	for(int i = 0; i < sz(s); i++)
		sa[i] = i, pos[i] = s[i];
	for(gap = 1; ; gap <<= 1){
		sort(sa, sa + sz(s), sufCmp);
		for(int i = 0; i + 1 < sz(s); i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < sz(s); i++) pos[sa[i]] = tmp[i];
		if(tmp[sz(s) - 1] == sz(s) - 1) break;
	}
	build_partisum();
	int match = 0;
	for(int i = 0; i < sz(s); i++){
		if(match) match--;
		if(!pos[i]) continue;
		int cur = i,
			pre = sa[pos[i] - 1];
		while(s[pre + match] == s[cur + match]) match++;
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
	for(int i = 1; i < sz(s); i++) if(lcp[i]){
		LL val = get(last[i], next[i] - 1);
		smax(ans, lcp[i] * val);
	}
	for(int i = 0; i < n; i++){
		LL match = 0;
		smax(match, lcp[tpos[i]]);
		smax(match, lcp[tpos[i] + 1]);
		if(match < siz[i])
			smax(ans, siz[i] * cost[i]);
	}
	cout << ans << endl;
	return 0;
}