#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 91;
const int V = 2;

int MODS[V] = {530305001, 330305111};
int PS[V] = {43, 125};

struct Hash{
	vector<int> h1, h2, pws;
	int MOD;
	int P;
	
	int query(int v){ // take out element at index v
		int sum = 0;
		if(v != 0){
			sum += h1[v - 1];
		}
		
		if(v != (int)h1.size() - 1){
			sum = (sum + ((h2[v + 1] * 1ll * pws[v]) % MOD)) % MOD;
		}
		
		return sum;
	}
	
	int Init(vector<int> st){
		if(st.size() == 0)
			return 0;
		int m = st.size();
		h1.resize(m);
		h2.resize(m);
		pws.resize(m);
		pws[0] = 1;
		for(int i = 1 ; i < st.size(); i ++ ){
			pws[i] = (pws[i - 1] * 1ll * P) % MOD;
		}
		int pv = 0;
		int ret = 0;
		for(int i = 0 ; i < st.size() ; i ++ ){
			pv = (((st[i] * 1ll * pws[i]) % MOD) + pv) % MOD;
			h1[i] = pv;
		}
		ret = pv;
		pv = 0;
		for(int i = (int)st.size() - 1; i >= 0 ; i -- ){
			pv = (pv * 1ll * P) % MOD;
			pv = (pv + st[i]) % MOD;
			h2[i] = pv;
		}
		return pv;
	}
};

Hash VALS[V][N];
vector<int> T[N];
int hsh[V][N];

const int MOD = 1000000087;

struct Valt{
	int R[V];
	bool operator< ( Valt &Y){
		for(int i = 0 ; i < V;i ++ ){
			if(R[i] != Y.R[i]){
				return R[i] < Y.R[i];
			}
		}
		return false;
	}
};

const int GMOD = (int)1e9 + 9;

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int e1[m], e2[m];
	for(int i = 0 ; i < m; i ++ ){
		cin >> e1[i] >> e2[i];
		T[e1[i]].push_back(e2[i]);
		T[e2[i]].push_back(e1[i]);
	}
	for(int i = 1; i <= n; i ++ ){
		sort(T[i].begin(), T[i].end());
	}
	for(int j = 0 ; j < V; j ++ ){
		for(int i = 1; i <= n; i ++ ){
			VALS[j][i].MOD = MODS[j];
			VALS[j][i].P = PS[j];
			hsh[j][i] = VALS[j][i].Init(T[i]);
		}
	}
	
	ll answ = 0;
	vector<pii> yi;
	for(int i = 1 ; i<= n; i ++ ){
		yi.push_back(mp(hsh[0][i],hsh[1][i]));
	}
	sort(yi.begin(), yi.end());
	int cnt = 1;
	for(int i = 1; i < n; i ++ ){
		if(yi[i] != yi[i - 1]){
			cnt = 1;
		}
		else{
			answ += cnt;
			cnt ++ ;
		}
	}
	bool eq;
	int id1, id2;
	int ii, jj;
	for(int j = 0 ; j < m ; j ++ ){
		eq = true;
		ii = e1[j];
		jj = e2[j];
		id1 = lower_bound(T[ii].begin(), T[ii].end(), jj) - T[ii].begin();
		id2 = lower_bound(T[jj].begin(), T[jj].end(), ii) - T[jj].begin();
		for(int z = 0 ; z < V;z ++ ){
			if(VALS[z][ii].query(id1) != VALS[z][jj].query(id2))
				eq = false;
		}
		if(eq)
			answ ++ ;
	}
	cout << answ << "\n";
	return 0;
}