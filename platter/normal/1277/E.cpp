#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int p[200000][3];

int find(int x,int type) {
	if (p[x][type]<0) {
		return x;
	}
	p[x][type]=find(p[x][type],type);
	return p[x][type];
}

void merge(int x, int y,int type) {
	x=find(x,type);
	y=find(y,type);
	if (x==y)
	return;
	p[x][type]+=p[y][type];
	p[y][type]=x;
}

int unionsize(int x) {
	return -p[x][0];
}

int main() {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int n,m,a,b;
		scanf("%d %d %d %d\n",&n,&m,&a,&b);
		for(int i=0;i<n;i++) {
			for(int j=0;j<3;j++) {
				p[i][j]=-1;
			}
		}
		a--;
		b--;
		for(int i=0;i<m;i++) {
			int u,v;
			scanf("%d %d\n",&u,&v);
			u--;
			v--;
			if (u!=a&&u!=b&&v!=a&&v!=b) {
				merge(u,v,0);
			}
			if (u!=a&&v!=a) {
				merge(u,v,1);
			}
			if (u!=b&&v!=b) {
				merge(u,v,2);
			}
		}
		long long aside=0;
		long long bside=0;
		for(int i=0;i<n;i++) {
			if (i==a||i==b)
			continue;
			if (find(b,1)==find(i,1)&&find(a,2)!=find(i,2)) {
				bside+=1;
			}
			if (find(b,1)!=find(i,1)&&find(a,2)==find(i,2)) {
				aside+=1;
			}
		}
		printf("%lld\n",aside*bside);
	}
	return 0;
}