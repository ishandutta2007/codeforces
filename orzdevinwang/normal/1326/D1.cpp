#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1019260817, G = 19491001;
int n, p, fa[N], ch[N][26], len[N], tot, las;
int Pre[N], Suf[N];
int up[20][N];
char s[N];
int getfa(int x) {
	for(; p < len[x] + 1 || s[p] != s[p - len[x] - 1]; x = fa[x]) ;
	return x; 
}
inline bool check(int x, int L) {
	if(x + (x - L) > n) 
		return false;
	return Pre[x - L] == Suf[n - (x - L) + 1];
}
int Get (int x, int now) {
	if(!check(now, len[x])) return -1;
	R(i, 19, 0) if(check(now, max(len[up[i][x]], 0))) x = up[i][x];
	return max(len[x], 0);
}
void ins() {
	int now = getfa(las);
	if(!ch[now][s[p] - 'a']) 
		++tot, fa[tot] = ch[getfa(fa[now])][s[p] - 'a'], 
		len[tot] = len[now] + 2, 
		ch[now][s[p] - 'a'] = tot;
	las = ch[now][s[p] - 'a'];
}
int ext[N], val[N], nsl;
char ns[N], sns[N];
void Work () {
	L(i, 0, tot) memset(ch[i], 0, sizeof(ch[i])), fa[i] = len[i] = 0;
	len[1] = -1, fa[0] = 1, nsl = 0, tot = 1, las = 0;
	L(i, 1, n) p = i, ins(), ext[i] = las;
	Pre[0] = Suf[n + 1] = 0;
	L(i, 1, n) Pre[i] = ((ll) Pre[i - 1] * G % mod + s[i]) % mod;
	R(i, n, 1) Suf[i] = ((ll) Suf[i + 1] * G % mod + s[i]) % mod;
	L(i, 0, tot) up[0][i] = fa[i];
	L(j, 1, 19) L(i, 0, tot) up[j][i] = up[j - 1][up[j - 1][i]];
	int chos = 0;
	L(i, 1, n) {
		val[i] = Get (ext[i], i);
		if(val[i] != -1 && chos * 2 - val[chos] < i * 2 - val[i]) 
			chos = i;
	}
	nsl = 0;
	L(i, 1, chos) ns[++nsl] = s[i];
	L(i, n - (chos - val[chos]) + 1, n) ns[++nsl] = s[i];
}
void Main () {
	int Len = 0;
	cin >> (s + 1), n = strlen(s + 1);
	Work (), Len = nsl;
	L(i, 1, Len) sns[i] = ns[i];
	reverse(s + 1, s + n + 1);
	Work ();
	
	if(Len >= nsl) {
		L(i, 1, Len) cout << sns[i];
		cout << '\n';
	}
	else {
		L(i, 1, nsl) cout << ns[i];
		cout << '\n';
	}
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}