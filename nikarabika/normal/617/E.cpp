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

const int maxn = 100 * 1000 + 1, maxval = 1 << 21, maxsq = 320;
LL cnt[maxval], Ans, ans[maxn], paxor[maxn];
int n, m, k, order[maxn], ql[maxn], qr[maxn];

bool cmp(int i, int j){
	if(ql[i] / maxsq != ql[j] / maxsq)
		return ql[i] < ql[j];
	return qr[i] < qr[j];
}

void add(int val){
	Ans += cnt[val ^ k];
	cnt[val]++;
	return;
}

void erase(int val){
	cnt[val]--;
	Ans -= cnt[val ^ k];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		paxor[i + 1] = paxor[i] ^ x;
	}
	for(int i = 0; i < m; i++){
		cin >> ql[i] >> qr[i];
		ql[i]--;
		order[i] = i;
	}
	sort(order, order + m, cmp);
	cnt[0] = 1;
	int st = 0, en = 0;
	for(int ii = 0; ii < m; ii++){
		int i = order[ii];
		while(st > ql[i])
			add(paxor[--st]);
		while(en < qr[i])
			add(paxor[++en]);
		while(st < ql[i])
			erase(paxor[st++]);
		while(en > qr[i])
			erase(paxor[en--]);
		ans[i] = Ans;
	}
	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';
	return 0;
}