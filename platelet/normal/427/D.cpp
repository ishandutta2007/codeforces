#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 5005;
char a[N], b[N], c[N*3];
int na, nb, n1, n2, n3, z[N*3], cfb[N], cfa[N];
void exKmp(char s[], int n) {
	z[1] = n;
	int zl = 0, zr = 0;
	rep(i, 2, n) if(zr < i) {
		for(int& j = z[i] = 0; s[i+j] == s[1+j]; j++);
		if(z[i]) zr = (zl = i) + z[i] - 1;
	} else if(i + z[i-zl+1] <= zr) z[i] = z[i-zl+1];
	else {
		for(int& j = z[i] = zr - i + 1; s[i+j] == s[1+j]; j++);
		zr = (zl = i) + z[i] - 1;
	}
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%s%s", a + 1, b + 1);
	na = strlen(a + 1), nb = strlen(b + 1);
	int ans = 1e9;
	rep(i, 1, na) {
		strcpy(c + 1, a + i), n2 = n1 = na - i + 1;
		c[++n2] = '@';
		strcpy(c + n2 + 1, b + 1), n3 = n2 += nb;
		c[++n3] = '#';
		strcpy(c + n3 + 1, a + 1), n3 += na;
		exKmp(c, n3), mem(cfa, 0), mem(cfb, 0);
		rep(j, n1 + 2, n2) cfb[z[j]]++;
		rep(j, n2 + 2, n3) cfa[z[j]]++;
		per(i, nb, 1) cfb[i] += cfb[i+1];
		per(i, na, 1) cfa[i] += cfa[i+1];
		rep(i, 1, na) if(cfb[i] == 1 && cfa[i] == 1)
			ans = min(ans, i);
	}
	return !(cout << (ans < 1e9 ? ans : -1));
}