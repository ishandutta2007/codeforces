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
#define last lasT
#define hash hasH

const int maxn = 300 * 1000 + 100;
const LL Mod = 1000LL * 1000 * 1000 + 7,
	  base = 313;
int sa[maxn],
	pos[maxn],
	tmp[maxn],
	lcp[maxn],
	next[maxn],
	last[maxn],
	next2[maxn],
	gap;
LL fen[maxn],
   sum[3][maxn];
string s, s1, s2, s3;

bool sufCmp(int i, int j){
	if(pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < sz(s) and j < sz(s)) ? pos[i] < pos[j] : i > j;
}

void add(int i){
	for(int j = 0; j < 3; j++)
		sum[j][i + 1] = sum[j][i];
	if(sa[i] < sz(s1) + 1 and sa[i] != sz(s1)) sum[0][i + 1]++;
	else if(sa[i] < sz(s1) + sz(s2) + 2 and sa[i] != sz(s1) + sz(s2) + 1) sum[1][i + 1]++;
	else if(sa[i] < sz(s1) + sz(s2) + sz(s3) + 3 and sa[i] != sz(s1) + sz(s2) + sz(s3) + 2) sum[2][i + 1]++;
	return;
}

int get(int id, int st, int en){
	return sum[id][en + 1] - sum[id][st];
}

void fenadd(int idx, LL val){
	fen[idx] += val;
	fen[idx] %= Mod;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2 >> s3;
	s = s1 + char('z' + 1) + s2 + char('z' + 2) + s3 + char('z' + 3);
	//computing sa array
	for(int i = 0; i < sz(s); i++)
		pos[i] = s[i], sa[i] = i;
	for(gap = 1;; gap <<= 1){
		sort(sa, sa + sz(s), sufCmp);
		for(int i = 0; i < sz(s) - 1; i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < sz(s); i++) pos[sa[i]] = tmp[i];
		if(tmp[sz(s) - 1] == sz(s) - 1) break;
	}
	//computing lcp array
	int match = 0;
	for(int i = 0; i < sz(s); i++){
		match = max(0, match - 1);
		if(!pos[i]) continue;
		int cur = sa[pos[i] - 1],
			pre = i;
		while(cur + match < sz(s) and pre + match < sz(s) and s[cur + match] == s[pre + match])
			match++;
		lcp[pos[i]] = match;
	}
	//having fun with a stack xD
	stack<int> stc;
	for(int i = 1; i < sz(s); i++){
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
	//computing answer :P
	for(int i = 0; i < sz(s); i++)
		add(i);
	for(int i = sz(s) - 1; i > 0; i--) if(lcp[next2[i]] != lcp[i]){
		int val = max(lcp[last[i]], lcp[next[i]]);
		LL cnt1 = get(0, last[i], next[i] - 1),
		   cnt2 = get(1, last[i], next[i] - 1),
		   cnt3 = get(2, last[i], next[i] - 1);
		fenadd(val + 1, (cnt1 * cnt2 * cnt3) % Mod);
		fenadd(lcp[i] + 1, (-cnt1 * cnt2 * cnt3) % Mod);
	}
	for(int i = 1; i < maxn; i++)
		fen[i] = (fen[i - 1] + fen[i]) % Mod;
	for(int i = 1; i <= min(sz(s1), min(sz(s2), sz(s3))); i++)
		cout << (fen[i] + Mod) % Mod << ' ';
	cout << '\n';
	return 0;
}