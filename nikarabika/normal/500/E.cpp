//segment pointeri mizanam ghorbatan elallah :D (in dafe ba araye mizanam haal konim :-""")
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69,
	  maxpos = 2000 * 1000 * 1000;
vector<piii> quer;
int LAST = 1;
LL pos[maxn], len[maxn], ans[maxn];
int n, q;

struct node{
	int val, chL, chR;
	bool laz;
	node(){
		chL = chR = val = laz = 0;
		return;
	}
	int left(void){
		if(chL == 0)
			chL = LAST++;
		return chL;
	}
	int right(void){
		if(chR == 0)
			chR = LAST++;
		return chR;
	}
} seg[maxn * 45];

void propagate(int, int, int);

void set_seg(LL st, LL en, LL l = 0, LL r = maxpos, int id = 0){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id].val = r - l;
		seg[id].laz = true;
		return;
	}
	LL mid = (l + r) >> 1;
	propagate(l, r, id);
	set_seg(st, en, l, mid, seg[id].left());
	set_seg(st, en, mid, r, seg[id].right());
	seg[id].val = seg[seg[id].left()].val + seg[seg[id].right()].val;
	return;
}

int get(LL st, LL en, LL l = 0, LL r = maxpos, int id = 0){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id].val;
	LL mid = (l + r) >> 1;
	propagate(l, r, id);
	return get(st, en, l, mid, seg[id].left())
		 + get(st, en, mid, r, seg[id].right());
}

void propagate(int l, int r, int id){
	if(seg[id].laz){
		int mid = (l + r) >> 1;
		set_seg(l, mid, l, mid, seg[id].left());
		set_seg(mid, r, mid, r, seg[id].right());
		seg[id].laz = false;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> pos[i] >> len[i];
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se;
		quer.PB({{fi - 1, se - 1}, i});
	}
	sort(quer.begin(), quer.end(), greater<piii>());
	int p = n - 1;
	for(int i = 0; i < q; i++){
		while(p >= quer[i].L.L){
			set_seg(pos[p], pos[p] + len[p]);
			p--;
		}
		ans[quer[i].R] = max(0LL, pos[quer[i].L.R] - pos[quer[i].L.L] - get(pos[quer[i].L.L], pos[quer[i].L.R]));
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}