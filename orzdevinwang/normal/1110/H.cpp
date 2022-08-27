#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 2007; 

int len;

int tot = 1, ch[N][10], fa[N], dep[N], n;

char l[N], r[N];

int ql, qr; 

bool la[N], ra[N];
void insert(char *s, int l) {
	int x = 1;
	L(i, 1, l) {
		if(ql) ra[x] = true;
		else la[x] = true;
		if(!ch[x][s[i] - '0']) ch[x][s[i] - '0'] = ++tot;
		x = ch[x][s[i] - '0'];
		dep[x] = i;
	}
	if(ql) qr = x;
	else ql = x;
} 

void bfs() {
	queue < int > q;
	L(i, 0, 9) 
		if(ch[1][i]) q.push(ch[1][i]), fa[ch[1][i]] = 1;
		else ch[1][i] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		L(i, 0, 9) {
			if(ch[u][i]) fa[ch[u][i]] = ch[fa[u]][i], q.push(ch[u][i]) ;
			else ch[u][i] = ch[fa[u]][i];
		}
	} 
}

int dp[N][N];
int f[N][10][N];
bool ok[N][N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> (l + 1) >> (r + 1) >> n;
	len = strlen(l + 1);
	
	int dl = strlen(l + 1), dr = strlen(r + 1);
	
	insert(l, dl);
	insert(r, dr);
	
	bfs();
	
	L(i, 1, tot) {
		L(o, 0, 9) {
			
			for(int j = i; j; j = fa[j]) {
				
				if(la[j]) {
					if(o != l[dep[j] + 1] - '0') {
						if(o || dep[j]) 
							f[i][o][dl - dep[j]] -= (o < l[dep[j] + 1] - '0');
					}
				}
				if(ra[j]) {
					if(o != r[dep[j] + 1] - '0') {
						if(o || dep[j])
							f[i][o][dr - dep[j]] += (o < r[dep[j] + 1] - '0');
					}
					else if(dep[j] == dr - 1) {
						f[i][o][1] += 1;
					}
				}
			}
			
			
			if(o) {
				L(j, dl, dr - 1) 
					f[i][o][j] += 1;
			}
			
			
			L(j, 1, n) f[i][o][j] += f[i][o][j - 1];
		}
	}
	
	me(dp, -0x3f); 
	dp[0][1] = 0;	
	L(i, 1, n) L(j, 1, tot) L(o, 0, 9) 
		dp[i][ch[j][o]] = max(dp[i][ch[j][o]], dp[i - 1][j] + f[j][o][n - i + 1]);
	int ns = -1;
	L(i, 1, tot) ns = max(ns, dp[n][i]);
	cout << ns << '\n';
	L(i, 1, tot) if(dp[n][i] == ns) ok[n][i] = true;
	
	R(i, n, 1) L(j, 1, tot) L(o, 0, 9) 
		if(dp[i - 1][j] + f[j][o][n - i + 1] == dp[i][ch[j][o]]) 
			ok[i - 1][j] |= ok[i][ch[j][o]];
	
	assert(ok[0][1]);
	
	L(i, 1, n) {
		int mn = 10;
		L(j, 1, tot) if(ok[i - 1][j]) L(o, 0, mn - 1) 
			if(dp[i - 1][j] + f[j][o][n - i + 1] == dp[i][ch[j][o]] && ok[i][ch[j][o]]) 
				mn = o;
	
		me(ok[i], 0);
		cout << ((char) (mn + '0'));
		L(j, 1, tot) 
			if(ok[i - 1][j] && dp[i - 1][j] + f[j][mn][n - i + 1] == dp[i][ch[j][mn]]) 
				ok[i][ch[j][mn]] = true;
	}
	return 0;
}