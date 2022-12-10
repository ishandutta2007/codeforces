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

const int maxn = 1e6 + 85 - 69;
int a[maxn],
	q1[maxn],
	q2[maxn],
	ps[maxn],
	fen[maxn],
	ans[maxn],
	ord[maxn],
	pos[maxn],
	n, q;
vector<int> all;

bool cmp(int i, int j){
	return q2[i] < q2[j];
}

void add(int idx, int val){
	idx++;
	if(!idx) return;
	while(idx < maxn){
		fen[idx] ^= val;
		idx += idx & -idx;
	}
	return;
}

int get(int idx){
	int ret = 0;
	while(idx){
		ret ^= fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int get(int st, int en){
	return get(en + 1) ^ get(st);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		all.PB(a[i]);
		ps[i + 1] = ps[i] ^ a[i];
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	memset(pos, -1, sizeof pos);
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d%d", q1 + i, q2 + i);
		q1[i]--, q2[i]--;
		ord[i] = i;
	}
	sort(ord, ord + q, cmp);
	int ptr = 0;
	for(int i = 0; i < n; i++){
		int id = lower_bound(all(all), a[i]) - all.begin();
		add(pos[id], a[i]);
		pos[id] = i;
		add(i, a[i]);
		while(ptr < q and q2[ord[ptr]] == i){
			ans[ord[ptr]] = ps[q2[ord[ptr]] + 1] ^ ps[q1[ord[ptr]]] ^ get(q1[ord[ptr]], q2[ord[ptr]]);
			ptr++;
		}
	}
	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return 0;
}