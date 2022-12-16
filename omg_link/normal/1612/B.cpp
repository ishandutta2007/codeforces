#include <stdio.h>
#include <string.h>
#define MN 100

int p[MN+5];
bool u[MN+5];

bool place(int pos,int v){
	if(u[v]) return false;
	u[v] = true;
	p[pos] = v;
	return true;
}

void solve(){
	memset(u,0,sizeof(u));
	memset(p,0xff,sizeof(p));
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	place(1,a);
	place(n/2+1,b);
	for(int i=2;i<=n/2;i++){
		for(int j=n;j>=a;j--)
			if(place(i,j)) break;
		if(p[i]==-1){
			puts("-1");
			return;
		}
	}
	for(int i=n/2+2;i<=n;i++){
		for(int j=1;j<=b;j++)
			if(place(i,j)) break;
		if(p[i]==-1){
			puts("-1");
			return;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",p[i]," \n"[i==n]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}