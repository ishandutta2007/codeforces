#include <cstdio>
#include <cstring>
const char f[] = "What are you doing at the end of the world? Are you busy? Will you save us?",
u[] = "What are you doing while sending \"",
v[] = "\"? Are you busy? Will you send \"",
w[] = "\"?";
int q, n, su, sv, sw;
long long len[100001], k;
char solve() {
	if(--k >= len[n]) return '.';
	while(n) {
		if(k < su) return u[k];
		k -= su;
		if(k < len[n-1]) {--n; continue;}
		k -= len[n-1];
		if(k < sv) return v[k];
		k -= sv;
		if(k < len[n-1]) {--n; continue;}
		k -= len[n-1];
		if(k < sw) return w[k];
	}
	return f[k];
}
int main() {
	scanf("%d", &q);
	*len = strlen(f), su = strlen(u), sv = strlen(v), sw = strlen(w);
	for(int i = 1; i <= 100000; ++i) {
		len[i] = su + sv + sw + len[i-1] + len[i-1];
		len[i] > 1e18 ? len[i] = 1e18 : 0;
	}
	while(q--) {
		scanf("%d%lld", &n, &k);
		printf("%c", solve());
	}
	return 0;
}