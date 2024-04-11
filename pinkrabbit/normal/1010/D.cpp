#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n;
int t[1000001],ls[1000001],rs[1000001];
int st[1000001];
int is[1000001];

void DFS1(int u){
	if(!t[u]) return;
	DFS1(ls[u]);
	if(t[u]!=4) DFS1(rs[u]);
	if(t[u]==1) st[u]=st[ls[u]]&st[rs[u]];
	if(t[u]==2) st[u]=st[ls[u]]|st[rs[u]];
	if(t[u]==3) st[u]=st[ls[u]]^st[rs[u]];
	if(t[u]==4) st[u]=st[ls[u]]^1;
}

void DFS2(int u,int s){
	if(!s) return;
	if(t[u]==0) {is[u]=1; return;}
	if(t[u]==1) DFS2(ls[u],st[rs[u]]), DFS2(rs[u],st[ls[u]]);
	if(t[u]==2) DFS2(ls[u],!st[rs[u]]), DFS2(rs[u],!st[ls[u]]);
	if(t[u]==3) DFS2(ls[u],1), DFS2(rs[u],1);
	if(t[u]==4) DFS2(ls[u],1);
}

int main(){
	char str[7]; int x,y;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s%d",str,&x);
		if(*str=='A') t[i]=1, scanf("%d",&y), ls[i]=x, rs[i]=y;
		if(*str=='O') t[i]=2, scanf("%d",&y), ls[i]=x, rs[i]=y;
		if(*str=='X') t[i]=3, scanf("%d",&y), ls[i]=x, rs[i]=y;
		if(*str=='N') t[i]=4, ls[i]=x;
		if(*str=='I') t[i]=0, st[i]=x;
	}
	DFS1(1);
	DFS2(1,1);
	F(i,1,n) if(!t[i]) printf("%d",is[i]^st[1]);
	return 0;
}