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
#define free freE

const int maxn = 5e5 + 85 - 69,
	  maxl = 25;
int seg[maxn * 4];
int sa[maxn],
	pos[maxn],
	tmp[maxn],
	lcp[maxn],
	spp[maxn],
	siz[maxn],
	tpos[maxn],
	last[maxn],
	next[maxn],
	spt[maxn][maxl],
	ans[maxn],
	gap, n, q;
vector<int> s;
vector<pair<pii, pii> > quer[maxn];

bool sufCmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < sz(s) and j < sz(s)) ? pos[i] < pos[j] : i > j;
}

void inc(int idx, int l = 0, int r = sz(s), int id = 1){
	if(idx < l or idx >= r)
		return;
	seg[id]++;
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	inc(idx, l, mid, id * 2 + 0);
	inc(idx, mid, r, id * 2 + 1);
	return;
}

int get(int st, int en, int l = 0, int r = sz(s), int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id * 2 + 0)
		+ get(st, en, mid, r, id * 2 + 1);
}

void build_spatab(void){
	spp[0] = -1;
	for(int i = 1; i < maxn; i++)
		spp[i] = spp[i>>1] + 1;
	for(int i = 0; i < maxn; i++)
		spt[i][0] = lcp[i];
	for(int j = 1; j < maxl; j++)
		for(int i = 0; i + (1 << j) <= maxn; i++)
			spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
	return;
}

int get_min(int st, int en){
	int lg = spp[en - st + 1];
	return min(spt[st][lg], spt[en - (1 << lg) + 1][lg]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		siz[i] = sz(t);
		tpos[i] = sz(s);
		for(int j = 0; j < sz(t); j++)
			s.PB(t[j]);
		s.PB(500 + i);
	}
	for(int i = 0; i < sz(s); i++)
		pos[i] = s[i], sa[i] = i;
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
		while(s[pre + match] == s[cur + match]) match++;
		lcp[pos[i]] = match;
	}
	build_spatab();
	for(int i = 0; i < n; i++){
		int lo = 0, hi = pos[tpos[i]] + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get_min(mid, pos[tpos[i]]) < siz[i])
				lo = mid;
			else
				hi = mid;
		}
		last[i] = lo;
		lo = pos[tpos[i]], hi = sz(s);
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get_min(pos[tpos[i]] + 1, mid) < siz[i])
				hi = mid;
			else
				lo = mid;
		}
		next[i] = hi;
	}
	for(int i = 0; i < q; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--, th--;
		if(fi)
			quer[fi - 1].PB(MP(MP(last[th], next[th]), MP(i, -1)));
		quer[se].PB(MP(MP(last[th], next[th]), MP(i, +1)));
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < siz[i]; j++)
			inc(pos[tpos[i] + j]);
		for(auto Q : quer[i])
			ans[Q.R.L] += Q.R.R * get(Q.L.L, Q.L.R);
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}