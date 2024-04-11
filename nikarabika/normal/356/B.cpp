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
#define sz(x) ((LL)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6 + 85 - 69,
	  maxa = 26;
int cnt[maxn][maxa],
	par[maxn],
	sum[maxa];
bool mark[maxn];
LL n, m, ans;
string s, t;

void shift(int &var){
	var += sz(t);
	if(var >= sz(s)) var -= sz(t);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m
		>> s
		>> t;
	if(sz(s) < sz(t)){
		swap(s, t);
		swap(n, m);
	}
	for(int i = 0; i < sz(t) and par[i] == -1; i++)
		for(int j = i; 1; j += sz(t)){
			if(j >= sz(s)) j -= sz(s);
			if(~par[j]) break;
			par[j] = i;
			int c = s[j] - 'a';
			cnt[i][c]++;
		}
	const LL len = sz(s) * n;
	const LL blolen = sz(s) / __gcd(sz(s), sz(t));
	for(int i = 0; i < sz(t); i++) if(!mark[i]){
		memset(sum, 0, sizeof sum);
		int x = m % blolen;
		for(int j = 0; j < x; j++){
			int c = s[(i + 1LL * j * sz(t)) % sz(s)] - 'a';
			sum[c]++;
		}
		int agab = i,
			jolo = (i + 1LL * x * sz(t)) % sz(s);
		for(int j = 0; j < blolen; j++){
			int id = (i + 1LL * j * sz(t)) % sz(s);
			if(id < sz(t)){
				mark[id] = true;
				ans += x - sum[t[id]-'a'];
				ans += m/blolen * (blolen - cnt[par[id]][t[id]-'a']);
			}
			sum[s[jolo]-'a']++;
			sum[s[agab]-'a']--;
			shift(jolo);
			shift(agab);
		}
	}
	cout << ans << '\n';
	return 0;
}