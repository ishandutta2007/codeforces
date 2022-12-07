#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, q;
int val[100010];
int s[5010], t[5010];
K p[5010];
vector<int> sons[5010];

int mx[5010];
K dp[5010][5010];
K dps[5010][5010];

void calc(int u){
	dp[u][0] = 1;
	FWD(i,0,q+1) dps[u][i+1] = dps[u][i] + dp[u][i];
	mx[u] = val[t[u]];
	for(int i = s[u]; i < t[u]; i++) mx[u] = max(mx[u], val[i]);
	for(int v : sons[u]){
		calc(v);
		FWD(i,0,q+1-mx[u]+mx[v]){
			int j = i + mx[u] - mx[v];
			dp[u][i] = dp[u][i] * dps[v][j] + dp[v][j] * dps[u][i] + dp[u][i] * dp[v][j];
		}
		FWD(i,0,q+1) dps[u][i+1] = dps[u][i] + dp[u][i];
	}
	BCK(i,q,0) dp[u][i] = (1-p[u]) * dp[u][i] + p[u] * dp[u][i-1];
	dp[u][0] *= 1-p[u];
	FWD(i,0,q+1) dps[u][i+1] = dps[u][i] + dp[u][i];
	//FWD(i,0,q+1) printf("dp[%d][%d] = %lf\n", u, i, dp[u][i]);
}

bool cmps(int a, int b){
	if(s[a] == s[b]) return t[a] > t[b];
	return s[a] < s[b];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	FWD(i,1,n+1) cin >> val[i];
	++n;
	FWD(i,0,q) cin >> s[i] >> t[i] >> p[i];
	s[q] = 1; t[q] = n; p[q] = 0;
	++q;
	vector<int> V;
	FWD(i,0,q) V.push_back(i);
	sort(V.begin(), V.end(), cmps);
	stack<int> S;
	FWD(i,0,q){
		while(S.size() >= 2 && t[S.top()] < s[V[i]]){
			int v = S.top();
			S.pop();
			sons[S.top()].push_back(v);
		}
		S.push(V[i]);
	}
	while(S.size() >= 2){
		int v = S.top();
		S.pop();
		sons[S.top()].push_back(v);
	}
	/*FWD(i,0,q){
		printf("sons of [%d, %d]:\n", s[i], t[i]);
		for(int v : sons[i]) printf("\t[%d, %d]\n", s[v], t[v]);
	}*/
	calc(q-1);
	K res = 0;
	FWD(i,0,q+1) res += (mx[q-1]+i) * dp[q-1][i];
	cout.precision(9);
	cout << fixed;
	cout << res << endl;
	return 0;
}