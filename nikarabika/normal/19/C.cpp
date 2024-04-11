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

const int maxn = 100 * 1000 + 10;
int a[maxn],
	sa[maxn],
	pos[maxn],
	tmp[maxn],
	lcp[maxn],
	Min[maxn],
	seg[maxn * 4],
	smest[maxn],
	n, gap;
vector<int> all,
	vec[maxn];

bool sufCmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < n and j < n) ? pos[i] < pos[j] : i > j;
}

void build(int l = 0, int r = n - 1, int id = 1){
	if(r - l == 1){
		seg[id] = lcp[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0],
			seg[id * 2 + 1]);
	return;
}

int get(int st, int en, int l = 0, int r = n - 1, int id = 1){
	if(st >= r or en <= l)
		return maxn * 100;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return min(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	if(n == 1){
		cout << 1 << '\n' << a[0] << '\n';
		return 0;
	}
	a[n] = -1;
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(all(all), a[i]) - all.begin();
		vec[a[i]].PB(i);
	}
	for(int i = 0; i < n; i++)
		sa[i] = i, pos[i] = a[i];
	for(gap = 1; ; gap <<= 1){
		sort(sa, sa + n, sufCmp);
		for(int i = 0; i + 1 < n; i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
		if(tmp[n - 1] == n - 1) break;
	}
	int match = 0;
	for(int i = 0; i < n; i++){
		if(match) match--;
		if(pos[i] == n - 1) continue;
		int pre = i,
			cur = sa[pos[i] + 1];
		while(a[pre + match] == a[cur + match]) match++;
		lcp[pos[i]] = match;
	}
	build();
	for(int i = 0; i < n; i++){
		smest[i] = maxn * 100;
		for(auto j : vec[a[i]]) if(j > i){
			int id1 = pos[i],
				id2 = pos[j];
			if(id1 > id2) swap(id1, id2);
			if(get(id1, id2) >= j - i){
				smest[i] = j - i;
				break;
			}
		}
	}
	smest[n] = maxn * 99;
	Min[n] = n;
	for(int i = n - 1; i >= 0; i--)
		if(smest[i] <= smest[Min[i + 1]]) Min[i] = i;
		else Min[i] = Min[i + 1];
	int id = 0;
	while(Min[id] != n)
		id = Min[id] + smest[Min[id]];
	cout << n - id << '\n';
	for(int i = id; i < n; i++)
		cout << all[a[i]] << ' ';
	cout << '\n';
	return 0;
}