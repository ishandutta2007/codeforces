#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
inline int add(int x , int y) {return x + y > P ? x + y - P : x + y;}
inline int sub(int x , int y) {return x < y ? x - y + P : x - y;};
inline int mul(int x , int y) {return 1ll * x * y % P;}
inline void upd(int &x , int y) {x = add(x , y);}

int n, d, ch[50010][11], fail[50010], ed[50010], cnt = 1, f[60][50010][2], p[60][2];
char s[1010], a[60], b[60];

void build() {
	int m = d / 2;
	for(int i = 1; i <= n - m + 1; i++) {
		int p = 1;
		for(int j = i; j <= i + m - 1; j++) {
			int c = s[j] - '0';
			if(!ch[p][c]) ch[p][c] = ++cnt;
			p = ch[p][c];
		}
		ed[p]++;
	}
	queue <int> q;
	for(int i = 0; i < 10; i++) {
		if(ch[1][i]) q.push(ch[1][i]), fail[ch[1][i]] = 1;
		else ch[1][i] = 1;
	}
	while(!q.empty()) {
		int p = q.front(); q.pop();
		for(int i = 0; i < 10; i++) {
			if(ch[p][i]) fail[ch[p][i]] = ch[fail[p]][i], q.push(ch[p][i]);
			else ch[p][i] = ch[fail[p]][i];
		}
	}
}

int S(char *a) {
	memset(f , 0 , sizeof f) , memset(p , 0 , sizeof p);
	p[d + 1][1] = p[d + 1][0] = 1;
	for(int i = d; i >= 1; i--) {
		p[i][0] = mul(10 , p[i + 1][0]);
		p[i][1] = add(p[i + 1][1] , mul(a[i] - '0' , p[i + 1][0]));
	}
	f[0][1][1] = 1;
	for(int i = 0; i < d; i++) for(int j = 1; j <= cnt; j++)
		if(!ed[j] && (f[i][j][0] || f[i][j][1])) for(int k = 0; k < 10; k++) {
			int p = ch[j][k];
			upd(f[i + 1][p][0] , f[i][j][0]);
			if(k < a[i + 1] - '0') upd(f[i + 1][p][0] , f[i][j][1]);
			else if(k == a[i + 1] - '0') upd(f[i + 1][p][1] , f[i][j][1]);
		}
	int ret = 0;
	for(int i = 1; i <= d; i++) for(int j = 1; j <= cnt; j++)
		if(ed[j]) upd(ret , add(mul(f[i][j][0] , p[i + 1][0]) , mul(f[i][j][1] , p[i + 1][1])));
	return ret;
}

int main() {
	scanf("%s%s%s" , s + 1 , a + 1 , b + 1);
	n = strlen(s + 1) , d = strlen(a + 1);
	int k = d; build();
	while(a[k] == '0') a[k--] = '9';
	--a[k];
	printf("%d\n" , sub(S(b) , S(a)));
	return 0;
}