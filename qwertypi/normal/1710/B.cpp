#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;

const int N = 200013 * 3;
const int LGN = 20;
int x[N], p[N];

struct BIT{
	int bit[N] = {0};
	void add(int x, int v){
		for(int i = x; i < N; i += i & -i){
			bit[i] += v;
		}
	}
	int qry(int x){
		int ret = 0;
		for(int i = x; i; i -= i & -i){
			ret += bit[i];
		}
		return ret;
	}
} bit0, bit1;

void add(int idx, int idv, int val){
	bit0.add(idx, -idv * val);
	bit1.add(idx, val);
}

int qry(int idx, int idv){
	return bit1.qry(idx) * idv + bit0.qry(idx);
}

int d[N];
int32_t lmn[LGN][N], rmn[LGN][N], qmn[LGN][N];

int qry_l(int l, int r){
	int d = __lg(r - l + 1);
	return max(lmn[d][l], lmn[d][r - (1 << d) + 1]);
}

int qry_r(int l, int r){
	int d = __lg(r - l + 1);
	return max(rmn[d][l], rmn[d][r - (1 << d) + 1]);
}

int qry_m(int l, int r){
	int d = __lg(r - l + 1);
	return max(qmn[d][l], qmn[d][r - (1 << d) + 1]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	fill(bit0.bit, bit0.bit + n * 3 + 10, 0);
	fill(bit1.bit, bit1.bit + n * 3 + 10, 0);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> p[i];
	}
	vector<int> sp;
	for(int i = 0; i < n; i++){
		sp.push_back(x[i] - p[i]);
		sp.push_back(x[i] + 0);
		sp.push_back(x[i] + p[i]);
	}
	sort(sp.begin(), sp.end());
	sp.resize(unique(sp.begin(), sp.end()) - sp.begin());
	map<int, int> M;
	for(int i = 0; i < sp.size(); i++){
		M[sp[i]] = i + 1;
	}
	for(int i = 0; i < n; i++){
		add(M[x[i] - p[i]], x[i] - p[i], 1);
		add(M[x[i]], x[i], -2);
		add(M[x[i] + p[i]], x[i] + p[i], 1);
	}
	for(int i = 1; i <= sp.size(); i++){
		d[i - 1] = qry(i, sp[i - 1]) - m;
	}
	for(int i = 0; i < sp.size(); i++){
		lmn[0][i] = min((long long) INT32_MAX, d[i] - sp[i]);
		rmn[0][i] = min((long long) INT32_MAX, d[i] + sp[i]);
		qmn[0][i] = min((long long) INT32_MAX, d[i]);
	}
	for(int j = 1; j < LGN; j++){
		for(int i = 0; i <= (int) sp.size() - (1 << j); i++){
			lmn[j][i] = max(lmn[j - 1][i], lmn[j - 1][i + (1 << j - 1)]);
		}
		for(int i = 0; i <= (int) sp.size() - (1 << j); i++){
			rmn[j][i] = max(rmn[j - 1][i], rmn[j - 1][i + (1 << j - 1)]);
		}
		for(int i = 0; i <= (int) sp.size() - (1 << j); i++){
			qmn[j][i] = max(qmn[j - 1][i], qmn[j - 1][i + (1 << j - 1)]);
		}
	}
	for(int i = 0; i < n; i++){
		int l = M[x[i] - p[i]] - 1, mid = M[x[i]] - 1, r = M[x[i] + p[i]] - 1;
		if(qry_l(l, mid) + sp[l] <= 0 && qry_r(mid, r) - sp[r] <= 0 && qry_m(0, l) <= 0 && qry_m(r, sp.size() - 1) <= 0){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	cout << '\n';
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}