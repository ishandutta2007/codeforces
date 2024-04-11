#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<char, pii> pcii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 200 * 1000 + 85 - 69;
set<int, greater<int> > s[maxn];
int seg[maxn * 4];
vector<int> all;
vector<pcii> quer;
int n;

void modify(int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or r <= idx)
		return;
	if(r - l == 1){
		seg[id] = (s[idx].size() ? *s[idx].begin() : -1);
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, l, mid, id * 2 + 0);
	modify(idx, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

int get(int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return -1;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

void add(int fi, int se){
	int id = lower_bound(all.begin(), all.end(), fi) - all.begin();
	int x = *s[id].begin();
	s[id].insert(se);
	if(x != *s[id].begin()) modify(id);
	return;
}

void remove(int fi, int se){
	int id = lower_bound(all.begin(), all.end(), fi) - all.begin();
	int x = *s[id].begin();
	s[id].erase(se);
	if(x != *s[id].begin()) modify(id);
	return;
}

pii qget(int fi, int se){
	int id = upper_bound(all.begin(), all.end(), fi) - all.begin();
	int lolen = 0, hilen = sz(all) - id;
	if(get(id, id + hilen) <= se)
		return MP(-1, -1);
	while(hilen - lolen > 1){
		int mid = (lolen + hilen) >> 1;
		if(get(id, id + mid) <= se)
			lolen = mid;
		else
			hilen = mid;
	}
	id += lolen;
	auto it = s[id].lower_bound(se);
	it--;
	return MP(all[id], *it);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(seg, -1, sizeof seg);
	cin >> n;
	for(int i = 0; i < n; i++){
		string ty;
		int fi, se;
		cin >> ty >> fi >> se;
		if(ty == "add"){
			all.PB(fi);
			quer.PB(MP('+', MP(fi, se)));
		}
		else if(ty == "remove")
			quer.PB(MP('-', MP(fi, se)));
		else
			quer.PB(MP('?', MP(fi, se)));
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++){
		char ty = quer[i].L;
		int fi = quer[i].R.L, se = quer[i].R.R;
		if(ty == '+')
			add(fi, se);
		else if(ty == '-')
			remove(fi, se);
		else{
			pii x = qget(fi, se);
			if(x.L == -1)
				cout << -1 << '\n';
			else
				cout << x.L << ' ' << x.R << '\n';
		}
	}
	return 0;
}