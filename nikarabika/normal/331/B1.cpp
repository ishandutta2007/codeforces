//sobskdrbhvk
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

const int maxn = 300 * 1000 + 85 - 69;
int seg[maxn * 3],
	p[maxn],
	pos[maxn];
int n;

void modify(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[id] = val < 0;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 1);
	modify(idx, val, mid, r, id * 2 + 0);
	seg[id] = seg[id * 2 + 1] + seg[id * 2 + 0];
	return;
}

int get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id * 2 + 1)
		+ get(st, en, mid, r, id * 2 + 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i], p[i]--;
		pos[p[i]] = i;
	}
	pos[n] = n;
	for(int i = 0; i < n; i++)
		modify(p[i], pos[p[i] + 1] - i);
	int q;
	cin >> q;
	while(q--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		fi--, se--;
		if(ty == 1)
			cout << get(fi, se) + 1 << '\n';
		else{
			swap(p[fi], p[se]);
			pos[p[fi]] = fi;
			pos[p[se]] = se;
			if(p[fi]) modify(p[fi] - 1, fi - pos[p[fi] - 1]);
			modify(p[fi], pos[p[fi] + 1] - fi);
			if(p[se]) modify(p[se] - 1, se - pos[p[se] - 1]);
			modify(p[se], pos[p[se] + 1] - se);
		}
	}
	return 0;
}