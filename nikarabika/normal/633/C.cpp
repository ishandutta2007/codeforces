//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
#define free Free

const int maxn = 10 * 1000 + 85 - 69,
	  maxm = 100 * 1000 + 85 - 69,
	  maxlen = 1000 * 1000 + 85 - 69,
	  root = 0;
int chld[maxlen][26],
	str[maxlen],
	par[maxn],
	n, m, free;
string s,
	   t[maxm],
	   tt[maxm];
bool dp[maxn];

void add(int idx, int pos = 0, int id = root){
	string &ss = tt[idx];
	if(pos == sz(ss)){
		str[id] = idx;
		return;
	}
	if(chld[id][ss[pos] - 'a'] == -1)
		chld[id][ss[pos] - 'a'] = ++free;
	add(idx, pos + 1, chld[id][ss[pos] - 'a']);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(chld, -1, sizeof chld);
	memset(str, -1, sizeof str);
	cin >> n;
	cin >> s;
	s = '*' + s;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> t[i];
		for(int j = 0; j < sz(t[i]); j++)
			tt[i] += char(t[i][j] >= 'a' ? t[i][j] : t[i][j] - 'A' + 'a');
		add(i);
	}
	dp[0] = true;
	for(int i = 1; i <= n; i++){
		int ptr = root;
		for(int len = 1; len <= 1000 and i - len >= 0; len++){
			int j = i - len + 1;
			ptr = chld[ptr][s[j] - 'a'];
			if(ptr == -1)
				break;
			if(str[ptr] != -1 and dp[j - 1])
				dp[i] = true, par[i] = str[ptr];
		}
	}
	int ptr = n;
	vector<int> ans;
	while(ptr){
		ans.PB(par[ptr]);
		ptr -= sz(t[par[ptr]]);
	}
	for(int i = sz(ans) - 1; i >= 0; i--)
		cout << t[ans[i]] << ' ';
	cout << endl;
	return 0;
}