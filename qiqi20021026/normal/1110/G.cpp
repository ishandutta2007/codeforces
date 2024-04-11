#include<bits/stdc++.h>

using namespace std;

#define N 3000000

int t,n,m,head[N],tot,x,y,d[N];
char s[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	++d[x]; ++d[y];
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
	e[++tot].v=x; e[tot].nxt=head[y]; head[y]=tot;
}

bool solve(){
	tot=0; for (int i=1;i<=m;++i) d[i]=head[i]=0;
	scanf("%d",&n);
	for (int i=1;i<n;++i){scanf("%d%d",&x,&y); add(x,y);}
	scanf("%s",s+1);
	m=n;
	for (int i=1;i<=n;++i)
		if (s[i]=='W'){
			add(i,m+1);
			add(m+1,m+2);
			add(m+1,m+3);
			m+=3;
		}
	if (n<=2) return 0;
	int cnt=0;
	for (int i=1;i<=m;++i){
		if (d[i]>=4) return 1;
		if (d[i]==3){
			++cnt;
			int sum=0;
			for (int j=head[i];j;j=e[j].nxt)
				sum+=d[e[j].v]>=2;
			if (sum>=2) return 1;
		}
	}
	if (cnt==2&&(m&1)) return 1;
	return 0;
}

int main(){
	scanf("%d",&t);
	while (t--) puts(solve()?"White":"Draw");;
	
	return 0;
}