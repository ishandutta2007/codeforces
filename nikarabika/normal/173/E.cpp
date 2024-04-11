//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u :)

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define endl '\n'

const int maxn = 1e5 + 85 - 69;
int sum[maxn * 4], Max[maxn * 4];
int n, qcnt, k;
int a[maxn], r[maxn], ans[maxn], order[maxn], max_emps[maxn];
vector<int> allage;
piii quer[maxn];

void inc_sum(int idx, int l = 0, int r = allage.size(), int id = 1){
	sum[id]++;
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	if(idx < mid)
		inc_sum(idx, l, mid, id * 2 + 0);
	else
		inc_sum(idx, mid, r, id * 2 + 1);
	return;
}

int get_sum(int st, int en, int l = 0, int r = allage.size(), int id = 1){
	if(st == l and en == r)
		return sum[id];
	int mid = (l + r) >> 1;
	int ret = 0;
	if(st < mid)
		ret += get_sum(st, min(mid, en), l, mid, id * 2 + 0);
	if(en > mid)
		ret += get_sum(max(st, mid), en, mid, r, id * 2 + 1);
	return ret;
}

void modify(int idx, int val, int l = 0, int r = allage.size(), int id = 1){
	if(r - l == 1){
		Max[id] = max(Max[id], val);
		return;
	}
	int mid = (l + r) >> 1;
	if(idx < mid)
		modify(idx, val, l, mid, id * 2 + 0);
	else
		modify(idx, val, mid, r, id * 2 + 1);
	Max[id] = max(Max[id * 2 + 0], Max[id * 2 + 1]);
	return;
}

int get(int st, int en, int l = 0, int r = allage.size(), int id = 1){
	if(st == l and en == r)
		return Max[id];
	int mid = (l + r) >> 1;
	int ret = -1;
	if(st < mid)
		ret = max(ret, get(st, min(mid, en), l, mid, id * 2 + 0));
	if(en > mid)
		ret = max(ret, get(max(st, mid), en, mid, r, id * 2 + 1));
	return ret;
}

void get_max_emps(void){
	int p = 0, q = 0;
	while(p < n){
		do{
			int id = lower_bound(allage.begin(), allage.end(), a[order[p]]) - allage.begin();
			inc_sum(id);
			//cout << "+ " << id << ' ' << p << ' ' << a[order[p]] << ' ' << a[order[p + 1]] << endl;
			p++;
		}while(p < n and r[order[p]] == r[order[p - 1]]);
		for(; q < p; q++){
			int id1 = lower_bound(allage.begin(), allage.end(), a[order[q]] - k) - allage.begin(),
				id2 = upper_bound(allage.begin(), allage.end(), a[order[q]] + k) - allage.begin();
			max_emps[order[q]] = get_sum(id1, id2);
			//cout << "? " << id1 << ' ' << id2 << endl;
		}
	}
	return;
}

bool orderCmp(int i, int j){
	return r[i] < r[j];
}

bool querCmp(piii x, piii y){
	return r[x.L.L] > r[y.L.L];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> r[i];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		allage.PB(a[i]);
	}
	for(int i = 0; i < n; i++)
		order[i] = i;
	sort(order, order + n, orderCmp);
	sort(allage.begin(), allage.end());
	allage.resize(unique(allage.begin(), allage.end()) - allage.begin());
	get_max_emps();
	cin >> qcnt;
	for(int i = 0; i < qcnt; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if(r[fi] < r[se])
			swap(fi, se);
		quer[i] = MP(MP(fi, se), i);
	}
	sort(quer, quer + qcnt, querCmp);
	reverse(order, order + n);
	int p = 0;
	for(int i = 0; i < qcnt; i++){
		while(p < n and r[order[p]] >= r[quer[i].L.L]){
			int id = lower_bound(allage.begin(), allage.end(), a[order[p]]) - allage.begin();
			modify(id, max_emps[order[p]]);
			p++;
		}
		int kage = min(a[quer[i].L.L], a[quer[i].L.R]),
			zage = max(a[quer[i].L.L], a[quer[i].L.R]);
		int st = zage - k, en = kage + k;
		if(st > en){
			ans[quer[i].R] = -1;
			continue;
		}
		int idst = lower_bound(allage.begin(), allage.end(), st) - allage.begin(),
			iden = upper_bound(allage.begin(), allage.end(), en) - allage.begin();
		ans[quer[i].R] = get(idst, iden);
		if(ans[quer[i].R] == 0)
			ans[quer[i].R] = -1;
	}
	for(int i = 0; i < qcnt; i++)
		cout << ans[i] << endl;
	return 0;
}