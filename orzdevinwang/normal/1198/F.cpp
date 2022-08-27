#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x * f; 
}
int n, ans[N], g[N], tot;
struct node {
	int val, id;
} f[N];
vector<int> ve[N];
map<int, int> A, B;
int main() {
	srand(233);
	const db st = clock();
	n = read();
	L(i, 1, n) {
		g[i] = read();
		if(!A[g[i]]) A[g[i]] = i, ++tot, f[tot].id = i, f[tot].val = g[i];
		else if(!B[g[i]]) B[g[i]] = i, ++tot, f[tot].id = i, f[tot].val = g[i];
		else ve[A[g[i]]].push_back(i);
	}
	while((clock() - st) / CLOCKS_PER_SEC < 0.1) {
		random_shuffle(f + 1, f + tot + 1);
		int now = 0, pp = 0, cnt = 0;
		L(i, 1, tot) {
			now = __gcd(now, f[i].val);
			if(now == 1) {
				++cnt;
				if(cnt == 2) {
					L(t, 1, pp) {
						ans[f[t].id] = 1;
						for(int p : ve[t]) ans[p] = 1;
					}
					L(t, pp + 1, n) {
						ans[f[t].id] = 2;
						for(int p : ve[t]) ans[p] = 2;
					}
					puts("YES");
					L(t, 1, n) printf("%d ", ans[t]);
					puts("");
					return 0;
				}
				pp = i, now = 0;
			}
		}
	}
	puts("NO");
	return 0;
}