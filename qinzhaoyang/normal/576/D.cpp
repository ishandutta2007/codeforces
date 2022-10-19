#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define bs bitset <N>

using namespace std;

typedef long long ll;
const int N = 160 , inf = 0x3f3f3f3f;

struct Edge{int u , v , w;} e[N];
int n , m;

struct M {
	bs a[N];
	inline void make() {for(int i = 1; i <= n; i++) a[i][i] = 1;}
	inline friend M operator * (M A , M B) {M ret;for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(A.a[i][j]) ret.a[i] |= B.a[j];return ret;}
};
M Pow(M x , int y) {M ret; ret.make();while(y) {if(y & 1) ret = ret * x;x = x * x , y >>= 1;}return ret;}

int main() {
	scanf("%d%d" , &n , &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d" , &e[i].u , &e[i].v , &e[i].w);
	sort(e + 1 , e + m + 1 , [&](Edge A , Edge B) {return A.w < B.w;});
	M A , B; A.make(); int now = 0 , ans = inf;
	for(int i = 1; i <= m; i++) {
		if(e[i].w - now > 0) A = A * Pow(B , e[i].w - now); B.a[e[i].u][e[i].v] = 1;
		now = e[i].w; int f[N]; memset(f , 0x3f , sizeof f); queue <int> q;
		for(int j = 1; j <= n; j++) if(A.a[1][j]) q.push(j) , f[j] = 0;
		while(!q.empty()) {
			int t = q.front(); q.pop();
			for(int j = 1; j <= n; j++) if(B.a[t][j] && f[j] == inf)
				f[j] = f[t] + 1 , q.push(j); 
		}
		ans = min(ans , now + f[n]);
	}
	if(ans == inf) printf("Impossible\n");
	else printf("%d\n" , ans);
	return 0;
}