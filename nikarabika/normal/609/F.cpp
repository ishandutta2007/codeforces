#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))

const int maxn = 2e5 + 85 - 69;
const int nodesize = maxn * 150;
pii po[maxn];
int cnt[maxn], Cnt;
multiset<pii> s;
int n, m;
vector<pii> all;

struct Node{
	const static LL maxval = 1000 * 1000 * 1000 * 2;
	LL val;
	int chL, chR;
	Node(){
		val = maxval;
		chL = chR = -1;
		return;
	}
	int l(){
		if(chL == -1)
			chL = ++Cnt;
		if(Cnt >= nodesize)
			assert(0);
		return chL;
	}
	int r(){
		if(chR == -1)
			chR = ++Cnt;
		if(Cnt >= nodesize)
			assert(0);
		return chR;
	}
} seg[nodesize];

int idof(LL val){return (lower_bound(all.begin(), all.end(), MP(val, -1LL))) -> R;}

void add(LL val, LL st, LL en, LL l = 0, LL r = 1000 * 1000 * 1000 + 1, int id = 0){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		smin(seg[id].val, val);
		return;
	}
	LL mid = (l + r) >> 1;
	add(val, st, en, l, mid, seg[id].l());
	add(val, st, en, mid, r, seg[id].r());
	return;
}

LL get(int idx, LL l = 0, LL r = 1000 * 1000 * 1000 + 1, int id = 0){
	if(idx < l or idx >= r or id == -1)
		return Node::maxval;
	if(r - l == 1)
		return seg[id].val;
	LL mid = (l + r) >> 1;
	if(idx < mid)
		return min(seg[id].val, get(idx, l, mid, seg[id].chL));
	return min(seg[id].val, get(idx, mid, r, seg[id].chR));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> po[i].L >> po[i].R;
		all.PB(MP(po[i].L, i));
		add(po[i].L, po[i].L, po[i].L + po[i].R + 1);
	}
	sort(all.begin(), all.end());
	for(int i = 0; i < m; i++){
		LL fi, se;
		cin >> fi >> se;
		LL val = get(fi);
		if(val == Node::maxval){
			s.insert(MP(fi, se));
			continue;
		}
		else{
			val = idof(val);
			po[val].R += se;
			cnt[val]++;
			while(1){
				auto it = s.lower_bound(MP(po[val].L, -1));
				if(it == s.end() or (it->L) > po[val].L + po[val].R)
					break;
				cnt[val]++;
				po[val].R = min(1000LL * 1000 * 1000 + 5, po[val].R + it->R);
				s.erase(it);
			}
			add(po[val].L, po[val].L, po[val].L + po[val].R + 1);
		}
	}
	for(int i = 0; i < n; i++)
		cout << cnt[i] << ' ' << po[i].R << endl;
	return 0;
}