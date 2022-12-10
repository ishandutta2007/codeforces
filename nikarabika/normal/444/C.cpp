//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000,
	  maxsq = 320;
int n, q;
LL seg2[maxn * 4],
   laz2[maxn * 4];
set<piii> s;

void add(LL val, int st, int en, int l = 0, int r = n, int id = 0){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg2[id] += val * (r - l);
		laz2[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 1);
	add(val, st, en, mid, r, id * 2 + 2);
	seg2[id] = seg2[id * 2 + 1] + seg2[id * 2 + 2] + laz2[id] * (r - l);
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 0){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg2[id];
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id * 2 + 1)
		+ get(st, en, mid, r, id * 2 + 2)
		+ laz2[id] * (min(r, en) - max(l, st));
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		s.insert(MP(MP(i, i), i + 1));
	for(int i = 0; i < q; i++){
		int ty, ql, qr, qv;
		scanf("%d%d%d", &ty, &ql, &qr);
		ql--, qr--;
		if(ty - 1)
			printf("%I64d\n", get(ql, qr + 1));
		else{
			scanf("%d", &qv);
			int l = ql;
			while(l <= qr){
				auto it = s.lower_bound(MP(MP(l, -1), -1));
				int newl = it->L.R,
					newr = it->L.L,
					newv = it->R;
				int r = min(newr, qr);
				//if(it->R != qv){
				s.erase(it);
				if(newl < l)
					s.insert(MP(MP(l - 1, newl), newv));
				if(newr > r)
					s.insert(MP(MP(newr, r + 1), newv));
				add(abs(qv - newv), l, r + 1);
				l = r + 1;
			}
			s.insert(MP(MP(qr, ql), qv));
		}
	}
	return 0;
}