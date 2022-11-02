#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+5;
int n, m, offset, cho[1<<18];
bool vis[N];
double ex[N], val[1<<17], totp[N], tote[N];
std::vector<std::pair<int, double>> in[N];

void upd(int x, double v) {
	val[x]=v;
	for(x+=offset; x/=2; ) {
		int l=cho[2*x], r=cho[2*x+1];
		cho[x]=val[l]<val[r]?l:r;
	}
}

int main() {
	assert(scanf("%d", &n)==1);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			int w;
			assert(scanf("%d", &w)==1);
			if(i!=j) in[j].emplace_back(i, w/100.0);
		}
	}
	for(int i=1; i<=n; ++i) tote[i]=totp[i]=1;
	for(int i=1; i<=n; ++i) ex[i]=1e100;
	offset=2<<(31^__builtin_clz(n));
	for(int i=0; i<offset; ++i) val[i]=1e100;
	for(int i=0; i<offset; ++i) cho[offset+i]=i;
	for(int i=offset; --i; ) cho[i]=cho[2*i];
	upd(n, ex[n]=0);
	while(cho[1]!=1) {
		int v=cho[1];
		vis[v]=true;
		upd(v, 1e100);
		for(auto e: in[v]) {
			int u=e.first;
			double p=e.second;
			if(!vis[u]) {
				tote[u]+=totp[u]*p*ex[v];
				totp[u]*=(1-p);
				double t=tote[u]/(1-totp[u]);
				if(t<ex[u]) upd(u, ex[u]=t);
			}
		}
	}
	printf("%.12f\n", ex[1]);
	return 0;
}