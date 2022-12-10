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
#define next nex
#define free fre

const int maxn = 500 * 1000 + 85 - 69,
	  Inf = 1000 * 1000 * 1000;
int sum[maxn],
	segmin[maxn * 4],
	segcnt[maxn * 4],
	sa[maxn],
	pos[maxn],
	tmp[maxn],
	lcp[maxn],
	last[maxn],
	next[maxn],
	next2[maxn],
	Id[maxn],
	opmcl[maxn],
	gap, n, free;
LL ans;
string s;
stack<int> stc;

bool sufCmp(int i, int j){
	if(pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < n and j < n) ? pos[i] < pos[j] : i > j;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		segmin[id] = sum[l + 1];
		segcnt[id] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	segmin[id] = min(segmin[id * 2 + 0], segmin[id * 2 + 1]);
	if(segmin[id * 2 + 0] <= segmin[id * 2 + 1])
		segcnt[id] += segcnt[id * 2 + 0];
	if(segmin[id * 2 + 0] >= segmin[id * 2 + 1])
		segcnt[id] += segcnt[id * 2 + 1];
	return;
}

pii merge(pii x, pii y){
	if(x.L < y.L)
		return x;
	if(x.L > y.L)
		return y;
	return MP(x.L, x.R + y.R);
}

pii getmin(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return MP(Inf, 0);
	if(st <= l and r <= en)
		return MP(segmin[id], segcnt[id]);
	int mid = (l + r) >> 1;
	return merge(getmin(st, en, l, mid, id * 2 + 0),
			getmin(st, en, mid, r, id * 2 + 1));
}

int Cnt(int idx){
	if(~Id[idx])
		return Id[idx];
	//cout << "Log " << idx << endl;
	if(idx == n)
		return Id[idx] = free++;
	if(lcp[idx] == lcp[next2[idx]])
		return Id[idx] = Cnt(next2[idx]);
	int parpos;
	if(lcp[last[idx]] > lcp[next[idx]])
		parpos = last[idx];
	else
		parpos = next[idx];
	int parid = Cnt(parpos);
	int newid = free++;
	if(opmcl[parid] == -Inf){
		opmcl[newid] = -Inf;
		return Id[idx] = newid;
	}
	int stpos = sa[idx];
	int lo = sa[idx] + lcp[parpos] - 1,
		hi = sa[idx] + lcp[idx];
	while(hi - lo > 1){
		int mid = (lo+hi)>>1;
		if(getmin(stpos + lcp[parpos], mid + 1).L - sum[stpos] >= 0)
			lo = mid;
		else
			hi = mid;
	}
	pii an = getmin(stpos + lcp[parpos], lo + 1);
	int minval = an.L - sum[stpos];
	int anval = ans;
	if(minval == 0)
		ans += an.R;
	//cout << ans - anval << endl;
	if(hi == sa[idx] + lcp[idx])
		opmcl[newid] = sum[sa[idx] + lcp[idx]] - sum[stpos];
	else
		opmcl[newid] = -Inf;
	//cout << opmcl[newid] << endl;
	return Id[idx] = newid;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + 1 - 2 * (s[i] == ')');
	build();
	for(int i = 0; i < n; i++)
		sa[i] = i, pos[i] = s[i];
	for(gap=1;;gap<<=1){
		sort(sa, sa + n, sufCmp);
		for(int i = 0; i + 1 < n; i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
		if(tmp[n - 1] == n - 1) break;
	}
	int match = 0;
	for(int i = 0; i < n; i++){
		if(match) match--;
		if(!pos[i]) continue;
		int cur = i,
			pre = sa[pos[i] - 1];
		while(max(pre, cur) + match <= n and s[pre + match] == s[cur + match]) match++;
		lcp[pos[i]] = match;
	}
	for(int i = 0; i < n; i++){
		while(sz(stc) and lcp[stc.top()] >= lcp[i]) stc.pop();
		last[i] = (sz(stc) ? stc.top() : 0);
		stc.push(i);
	}
	while(sz(stc)) stc.pop();
	for(int i = n - 1; i >= 0; i--){
		while(sz(stc) and lcp[stc.top()] >= lcp[i]) stc.pop();
		next[i] = (sz(stc) ? stc.top() : n);
		stc.push(i);
	}
	while(sz(stc)) stc.pop();
	for(int i = n - 1; i >= 0; i--){
		while(sz(stc) and lcp[stc.top()] > lcp[i]) stc.pop();
		next2[i] = (sz(stc) ? stc.top() : n);
		stc.push(i);
	}/*
	for(int i = 0; i < n; i++)
		cout << sa[i] << " \n"[i == n - 1];
	for(int i = 0; i < n; i++)
		cout << lcp[i] << " \n"[i == n - 1];
	for(int i = 0; i < n; i++)
		cout << last[i] << " \n"[i == n - 1];
	for(int i = 0; i < n; i++)
		cout << next[i] << " \n"[i == n - 1];*/
	memset(Id, -1, sizeof Id);
	for(int i = 0; i < n; i++)
		if(!(~Id[i]))
			Cnt(i);
	for(int i = 0; i < n; i++){
		if(n - sa[i] > max(lcp[i], lcp[i + 1])){
			int ananan = max(lcp[i], lcp[i + 1]);
			int lo = sa[i] + ananan - 1,
				hi = n;
			int parid;
			if(lcp[i] > lcp[i + 1]) parid = Id[i];
			else parid = Id[i + 1];
			if(opmcl[parid] == -Inf) continue;
			while(hi - lo > 1){
				int mid = (lo+hi)>>1;
				if(getmin(sa[i] + ananan, mid + 1).L - sum[sa[i]] >= 0)
					lo = mid;
				else
					hi = mid;
			}
			pii an = getmin(sa[i] + ananan, lo + 1);
			if(an.L - sum[sa[i]] == 0){
				ans += an.R;
				//cout << "khar" << i << ' ' << an.R << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}