#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int ch[N][26], tot = 1;
int get(int x, bool o) {
	unsigned int msk = 0;
	L(i, 0, 25) if(ch[x][i]) msk |= (1 << get(ch[x][i], o));
	if(!msk) return o;
	return __builtin_ctz(~msk);
}
int n, k;
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	while(n--) {
		cin >> (s + 1);
		int l = strlen(s + 1), now = 1;
		L(i, 1, l) {
			if(!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot;
			now = ch[now][s[i] - 'a'];
		}
	}
	int s0 = get(1, 0), s1 = get(1, 1);
//	cout << s0 << " " << s1 << "\n";
	if(s0 == 0) return cout << "Second\n", 0;
	if(s1 > 1) return cout << "First\n", 0;
	if(k & 1) cout << "First\n";
	else cout << "Second\n";
	return 0;
}