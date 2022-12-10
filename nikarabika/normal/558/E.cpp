//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//Man am A _____ & a pair of Iz wayTn' 230u :)

const int maxn = 1e5 + 85 - 69;
int seg[26][maxn * 4], laz[26][maxn * 4];
string s;
int n, m;

inline void propagate(int, int, int, int);

void sefrkon(int segid, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(l >= st and r <= en){
		laz[segid][id] = 0;
		seg[segid][id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	propagate(segid, l, r, id);
	sefrkon(segid, st, en, l, mid, id * 2 + 0);
	sefrkon(segid, st, en, mid, r, id * 2 + 1);
	seg[segid][id] = seg[segid][id * 2 + 0] + seg[segid][id * 2 + 1];
	return;
}

void yekon(int segid, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[segid][id] = r - l;
		laz[segid][id] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	propagate(segid, l, r, id);
	yekon(segid, st, en, l, mid, id * 2 + 0);
	yekon(segid, st, en, mid, r, id * 2 + 1);
	seg[segid][id] = seg[segid][id * 2 + 0] + seg[segid][id * 2 + 1];
	return;
}

int get(int segid, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[segid][id];
	int mid = (l + r) >> 1;
	propagate(segid, l, r, id);
	return get(segid, st, en, l, mid, id * 2 + 0)
		 + get(segid, st, en, mid, r, id * 2 + 1);
}

void build_string(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		for(int i = 0; i < 26; i++)
			if(seg[i][id])
				s[l] = i + 'a';
		return;
	}
	for(int i = 0; i < 26; i++)
		propagate(i, l, r, id);
	int mid = (l + r) >> 1;
	build_string(l, mid, id * 2 + 0);
	build_string(mid, r, id * 2 + 1);
	return;
}

inline void propagate(int segid, int l, int r, int id){
	if(laz[segid][id] == 0){
		seg[segid][id * 2 + 0] = 0;
		laz[segid][id * 2 + 0] = 0;
		seg[segid][id * 2 + 1] = 0;
		laz[segid][id * 2 + 1] = 0;
	}
	else if(laz[segid][id] == 1){
		int mid = (l + r) >> 1;
		seg[segid][id * 2 + 0] = mid - l;
		laz[segid][id * 2 + 0] = 1;
		seg[segid][id * 2 + 1] = r - mid;
		laz[segid][id * 2 + 1] = 1;
	}
	laz[segid][id] = -1;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(laz, -1, sizeof laz);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++)
		yekon(s[i] - 'a', i, i + 1);
	for(int i = 0; i < m; i++){
		int fi, se, ty;
		cin >> fi >> se >> ty;
		fi--;
		int cnt[26];
		for(int i = 0; i < 26; i++){
			cnt[i] = get(i, fi, se);
			sefrkon(i, fi, se);
		}
		for(int i = 0; i < 26; i++){
			if(ty and cnt[i])
				yekon(i, fi, fi + cnt[i]), fi += cnt[i];
			else if(!ty and cnt[25 - i])
				yekon(25 - i, fi, fi + cnt[25 - i]), fi += cnt[25 - i];
		}
	}
	build_string();
	cout << s;
	return 0;
}