#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, k, ans, a[N], b[N], f[N*2], g[N*2], h[N*2];
char s[N];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int calc(int x){
	int y=find(x+k);
	x=find(x);
	if(h[x] || h[y]) return h[x]?g[x]:g[y];
	else return min(g[x], g[y]);
}
void merge(int x, int y){
	x=find(x), y=find(y);
	f[x]=y, g[y]+=g[x], h[y]+=h[x];
}
int main() {
	scanf("%d%d%s", &n, &k, s+1);
	for(int i=1, x, y; i<=k; ++i){
		scanf("%d", &x);
		while(x--){
			scanf("%d", &y);
			if(a[y]) b[y]=i; else a[y]=i;
		}
	}
	for(int i=1; i<=k*2; ++i) f[i]=i, g[i]=i<=k;
	for(int i=1; i<=n; ++i, printf("%d\n", ans)) if(a[i]){
		if(b[i]){
			if(s[i]=='1'){
				if(find(a[i])!=find(b[i])){
					ans-=calc(a[i])+calc(b[i]);
					merge(b[i], a[i]), merge(b[i]+k, a[i]+k);
					ans+=calc(a[i]);
				}
			}
			else{
				if(find(a[i])!=find(b[i]+k)){
					ans-=calc(a[i])+calc(b[i]);
					merge(b[i]+k, a[i]), merge(b[i], a[i]+k);
					ans+=calc(a[i]);
				}
			}
		}
		else{
			if(s[i]=='1') ans-=calc(a[i]), ++h[find(a[i]+k)], ans+=calc(a[i]);
			else ans-=calc(a[i]), ++h[find(a[i])], ans+=calc(a[i]);
		}
	}
	return 0;
}