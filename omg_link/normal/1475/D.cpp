#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#define MN 200000
typedef long long LL;

int n,m;
int a[MN+5],b[MN+5];
std::vector<int> c[3];
LL f[MN*2+5],g[MN*2+5][3];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	c[1].clear();
	c[2].clear();
	int sb = 0;
	for(int i=1;i<=n;i++){
		c[b[i]].push_back(a[i]);
		sb += b[i];
	}
	c[1].push_back(0);
	c[1].push_back(0);
	c[2].push_back(0);
	std::sort(c[1].begin(),c[1].end(),std::greater<int>());
	std::sort(c[2].begin(),c[2].end(),std::greater<int>());
	f[1] = f[0]+c[1][0];
	g[1][1] = 1;
	g[1][2] = 0;
	if(f[1]>=m){
		printf("%d\n",1);
		return;
	}
	for(int i=2;i<=sb;i++){
		if(f[i-2]+c[2][g[i-2][2]]>=f[i-1]+c[1][g[i-1][1]]){
			f[i] = f[i-2]+c[2][g[i-2][2]];
			g[i][1] = g[i-2][1];
			g[i][2] = g[i-2][2]+1;
		}else{
			f[i] = f[i-1]+c[1][g[i-1][1]];
			g[i][1] = g[i-1][1]+1;
			g[i][2] = g[i-1][2];
		}
		if(f[i]>=m){
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}