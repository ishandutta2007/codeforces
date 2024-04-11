#include <cstdio>
#include <cctype>
using namespace std;
const int N = 2e5 + 1;

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

int T, n, m, t, u, v, x[N], y[N], fa[N], head[N], nxt[N << 1], to[N << 1], eid;
long long a[N], b[N];
inline void addedge(int u, int v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void merge(int u, int v){
	u = find(u), v = find(v);
	if(u != v){
		fa[v] = u;
		a[u] += a[v];
		b[u] += b[v];
	}
}

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		eid = 1;
		for(int i = 1; i <= n; i++) a[i]=read(), fa[i] = i, head[i] = 0;
		for(int i = 1; i <= n; i++) b[i]=read();
		for(int i = 1; i <= m; i++){
			x[i]=read(),y[i]=read();
		}
		for(int i = 1; i <= m; i++){
			u = find(x[i]), v = find(y[i]);
			addedge(u, v), addedge(v, u);
		}
		for(int i = 1; i <= n; i++){
			u = find(to[head[i]]);
			for(int e = nxt[head[i]]; e; e = nxt[e])
				merge(u, find(to[e]));
		}
		bool flag = true;
		for(int i = 1; flag && i <= n; i++) if(head[i]){
			u = find(i), v = find(to[head[i]]);
			flag = u == v ? !(((a[u] - b[u])%2+2)%2==1) : (a[u] - b[u]) == (a[v] - b[v]);
		}else if(fa[i] == i) flag = a[i] == b[i];
		puts(flag ? "YES" : "NO");
	}
	return 0;
}