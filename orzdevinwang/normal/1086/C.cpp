#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, k, ch[26];
bool vis[26], ok;
char s[N], a[N], b[N];
void dfs (int x, bool o1, bool o2) {
	if(ok) return ;
	if(x == n + 1 || (!o1 && !o2)) {
		ok = true;
		cout << "YES\n";
		int now = 0;
		L(i, 0, k - 1) if(ch[i] == -1) {
			while (now < k && vis[now]) ++now;
			if(now == k) assert (0);
			vis[now] = true;
			ch[i] = now;
		}
		L(i, 0, k - 1) cout << (char) (ch[i] + 'a');
		cout << '\n';
		return ;
	}
	int vl = (o1 ? a[x] - 'a' : 0), vr = (o2 ? b[x] - 'a' : k - 1);
	if(ch[s[x] - 'a'] != -1) {
		int t = ch[s[x] - 'a'];
		if(vl <= t && t <= vr) dfs(x + 1, o1 & (t == a[x] - 'a'), o2 & (t == b[x] - 'a'));
		else return ;
		return ;
	}
	L(z, vl, vr) if(!vis[z]) {
		ch[s[x] - 'a'] = z, vis[z] = true;
		dfs (x + 1, o1 & (z == a[x] - 'a'), o2 & (z == b[x] - 'a'));
		ch[s[x] - 'a'] = -1, vis[z] = false;
	}
}
void Main () {
	ok = false;
	memset(vis, 0, sizeof(vis));
	memset(ch, -1, sizeof(ch));
	cin >> k >> (s + 1) >> (a + 1) >> (b + 1);
	n = strlen(s + 1);
	dfs (1, true, true);
	if(!ok) cout << "NO\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}