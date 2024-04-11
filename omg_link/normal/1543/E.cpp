#include <stdio.h>
#include <vector>
#define MN (1<<16)

int id[MN],idr[MN];
std::vector<int> e[MN];

void add(int u,int v){
	e[u].push_back(v);
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		e[i].clear();
		id[i] = 0;
	}
	for(int i=0;i<n*(1<<(n-1));i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	std::vector<int> p[17];
	id[0] = 0;
	for(int i=0;i<n;i++){
		id[e[0][i]] = (1<<i);
		idr[(1<<i)] = e[0][i];
	}
	for(int i=0;i<(1<<n);i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) cnt++;
		}
		p[cnt].push_back(i);
	}
	for(int i=2;i<=n;i++){
		for(int x:p[i]){
			std::vector<int> ss;
			for(int j=0;j<n;j++){
				if(x&(1<<j)) ss.push_back(x^(1<<j));
			}
			int p1 = idr[ss[0]];
			int p2 = idr[ss[1]];
			bool flag = false;
			for(int p1i=0;p1i<n&&flag==false;p1i++){
				int y = e[p1][p1i];
				if(y==0||id[y]!=0) continue;
				for(int p2i=0;p2i<n&&flag==false;p2i++){
					if(y==e[p2][p2i]){
						id[y] = x;
						idr[x] = y;
						flag = true;
					}
				}
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
		idr[id[i]] = i;
	for(int i=0;i<(1<<n);i++)
		printf("%d ",idr[i]);
	puts("");
	if(n==1||n==2||n==4||n==8||n==16){
		for(int i=0;i<(1<<n);i++){
			int col = 0;
			for(int j=0;j<16;j++){
				if(id[i]&(1<<j)) col ^= j;
			}
			printf("%d ",col);
		}
		puts("");
	}else{
		puts("-1");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}