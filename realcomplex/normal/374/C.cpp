#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e6 + 9;
const int MAXS = 1005;

int g[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<int> T[N];
int indx[MAXS][MAXS];
char conf[MAXS][MAXS];

bool check(int i1, int j1, int i2, int j2){
	if(conf[i1][j1] == 'D' and conf[i2][j2] == 'I')
		return true;
	if(conf[i1][j1] == 'I' and conf[i2][j2] == 'M')
		return true;
	if(conf[i1][j1] == 'M' and conf[i2][j2] == 'A')
		return true;
	if(conf[i1][j1] == 'A' and conf[i2][j2] == 'D')	
		return true;
	return false;
}

int state[N];
int deg[N];
char let[N];

void dfs(int u){
	if(state[u] == 2)
		return;
	if(state[u] == 1){
		cout << "Poor Inna!\n";
		exit(0);
	}
	state[u] = 1;
	for(auto x : T[u]){
		dfs(x);
	}
	state[u] = 2;
}

int typ(char x){
	if(x == 'D')
		return 0;
	if(x == 'I')
		return 1;
	if(x == 'M')
		return 2;
	return 3;
}

int dp[N];
int msk[N];

int main(){
	fastIO;
	memset(conf, '&', sizeof conf);
	int n, m;
	cin >> n >> m;
	bool isd = false;
	for(int i = 1;i <= n;i ++ ){
		for(int j = 1; j <= m; j ++ ){
			indx[i][j] = (i - 1) * m + j;
			cin >> conf[i][j];
			let[indx[i][j]] = conf[i][j];
			if(conf[i][j] == 'D')
				isd = true;
		}
	}
	if(!isd){
		cout << "Poor Dima!\n";
		return 0;
	}
	for(int i = 1;i <= n;i ++ ){
		for(int j = 1;j <= m;j ++ ){
			for(int y = 0; y < 4; y ++ ){
				if(check(i, j, i + g[y][0], j + g[y][1])){
					T[indx[i][j]].push_back(indx[i + g[y][0]][j + g[y][1]]);
				}
			}
		}
	}
	int nn = n * m;
	for(int i = 1; i <= nn; i ++ ){
		dfs(i);
	}
	for(int i = 1; i <= nn; i ++ ){
		for(auto x : T[i])
			deg[x] ++ ;
	} 
	queue<int> st;
	for(int i = 1; i <= nn; i ++ ){
		if(deg[i] == 0){
			st.push(i);
			msk[i] = (1 << typ(let[i]));
		}
	}	
	int node;
	int mask;
	int nx_mask;
	int answ;
	while(!st.empty()){
		node = st.front();
		mask = msk[node];
		if(mask > 0 and mask % 2 == 0){
			mask = 0;
		}
		st.pop();
		for(auto x : T[node]){
			deg[x] -- ; 
			if(deg[x] == 0){
				nx_mask = mask | (1 << typ(let[x]));
				answ = dp[node] + (nx_mask == 15);
				if(nx_mask == 15)
					nx_mask = 0;
				if(dp[x] < answ){
					dp[x] = answ;
					msk[x] = nx_mask;
				}
				else if(dp[x] == answ){
					msk[x] = max(nx_mask, msk[x]);
				}
				st.push(x);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= nn; i ++ ){
		ans = max(ans, dp[i]);
	}
	if(ans == 0){
		cout << "Poor Dima!\n";
	}
	else{
		cout << ans << "\n";
	}
	return 0;
}