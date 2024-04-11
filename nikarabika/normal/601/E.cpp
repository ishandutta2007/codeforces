//sobskdrbhvk
//accept sho, plz ;;)
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 5000,
	  maxk = 1000,
	  maxq = 30000,
	  maxq1 = 10000;
const LL P = 1000LL * 1000 * 10 + 19, Q = 1000LL * 1000 * 1000 + 7;
vector<int> vec[maxq * 3];
vector<int> quer, qtime;
int qid[maxq];
LL val[maxn + maxq1 + 1], ans[maxq];
int wei[maxn + maxq1 + 1], sttime[maxn + maxq1 + 1], fitime[maxn + maxq1 + 1];
int n, k, q;

struct knapsack{
	LL dp[maxk];
	knapsack(){
		for(int i = 0; i < maxk; i++)
			dp[i] = 0;
		return;
	}
	void shiaf_kon(LL val, int wei){
		for(int i = maxk - 1; i >= wei; i--)
			smax(dp[i], dp[i - wei] + val);
		smax(dp[wei - 1], val);
		return;
	}
	LL operator[](int i){return dp[i];}
};

void add(int idx, int st, int en, int l = 0, int r = sz(quer), int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		vec[id].PB(idx);
		return;
	}
	int mid = (l + r + 1) >> 1;
	add(idx, st, en, l, mid, id * 2 + 0);
	add(idx, st, en, mid, r, id * 2 + 1);
	return;
}

void build(knapsack knap, int l = 0, int r = sz(quer), int id = 1){
	for(auto exid : vec[id])
		knap.shiaf_kon(val[exid], wei[exid]);
	if(r - l == 1){
		for(int i = k - 1; i >= 0; i--)
				ans[l] = ((((ans[l] % Q) * P) % Q) + knap[i]) % Q;
		return;
	}
	int mid = (l + r + 1) >> 1;
	build(knap, l, mid, id * 2 + 0);
	build(knap, mid, r, id * 2 + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(fitime, 127, sizeof fitime);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> val[i] >> wei[i];
	cin >> q;
	for(int i = 0; i < q; i++){
		int ty;
		cin >> ty;
		ty--;		//0-base, anywhere and anytime :D
		if(ty == 0){
			cin >> val[n] >> wei[n];
			sttime[n++] = i;
		}
		else if(ty == 1){
			int id;
			cin >> id, id--;
			fitime[id] = i;
		}
		else{
			quer.PB(i);
			qtime.PB(i);
		}
	}
	for(int i = 0; i < n; i++){
		int stid = lower_bound(qtime.begin(), qtime.end(), sttime[i]) - qtime.begin(),
			fiid = lower_bound(qtime.begin(), qtime.end(), fitime[i]) - qtime.begin();
		add(i, stid, fiid);
	}
	knapsack empty_knapsack;
	build(empty_knapsack);
	for(int i = 0; i < sz(quer); i++)
			cout << ans[i] << '\n';
	return 0;
}