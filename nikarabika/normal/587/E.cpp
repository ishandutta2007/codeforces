//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
int laz[maxn * 4],
	a[maxn],
	n, q;

struct node{
	int bs[32],
		sz;
	bool cnt[32];
	bool has(void){
		return sz and !bs[0];
	}
	void add(int val, bool ty = 1){
		for(int i = 0; i < sz; i++)
			if((bs[i] & -bs[i]) & val){
				val ^= bs[i];
				ty ^= cnt[i];
			}
		if(!val and !ty) return;
		if(val)
			for(int i = 0; i < sz; i++)
				if(bs[i] & (val & -val)){
					bs[i] ^= val;
					cnt[i] ^= ty;
				}
		bs[sz] = val;
		cnt[sz] = ty;
		if(val == 0){
			if(sz == 0 or bs[0]){
				swap(bs[sz], bs[0]);
				swap(cnt[sz], cnt[0]);
				sz++;
				return;
			}
			return;
		}
		sz++;
	}
	void apply(int val){
		int tmp[sz],
			tz = sz;
		bool typ[sz];
		memcpy(tmp, bs, sz * 4);
		memcpy(typ, cnt, sz);
		sz = 0;
		for(int i = 0; i < tz; i++)
			add(tmp[i] ^ (typ[i] * val), typ[i]);
		return;
	}
	int size(void){
		return sz - (bs[0] == 0);
	}
} seg[maxn * 4];

node operator^(node &le, node &ri){
	node ret = le;
	for(int i = 0; i < ri.sz; i++)
		ret.add(ri.bs[i], ri.cnt[i]);
	return ret;
}

void push(int id);

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id].add(a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id<<1|0);
	build(mid, r, id<<1|1);
	seg[id] = seg[id<<1|0] ^ seg[id<<1|1];
	return;
}

void apply(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id].apply(val);
		laz[id] ^= val;
		return;
	}
	int mid = (l + r) >> 1;
	if(laz[id]) push(id);
	apply(val, st, en, l, mid, id<<1|0);
	apply(val, st, en, mid, r, id<<1|1);
	seg[id] = seg[id<<1|0] ^ seg[id<<1|1];
	return;
}

void push(int id){
	apply(laz[id], 0, 1, 0, 1, id<<1|0);
	apply(laz[id], 0, 1, 0, 1, id<<1|1);
	laz[id] = 0;
}

node get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(laz[id]) push(id);
	if(en <= mid) return get(st, en, l, mid, id<<1|0);
	if(st >= mid) return get(st, en, mid, r, id<<1|1);
	node tmp1 = get(st, en, l, mid, id<<1|0),
		 tmp2 = get(st, en, mid, r, id<<1|1);
	return tmp1 ^ tmp2;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	build();
	while(q--){
		int ty, fi, se, th;
		scanf("%d%d%d", &ty, &fi, &se);
		fi--;
		if(ty == 1){
			scanf("%d", &th);
			apply(th, fi, se);
		}
		else if(ty == 2)
			printf("%d\n", (1 << get(fi, se).size()));
	}
	return 0;
}