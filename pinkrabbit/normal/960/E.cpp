#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long

int Mod=1000000007;
int n,q;
int val[200001];

int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y) {
	nxt[++tot]=h[x];
	to[tot]=y;
	h[x]=tot;
}

int f[200001],siz[200001],dep[200001];

ll Ans;

void DFS(int u,int fa) {
	f[u]=1;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	eF(i,u) if(to[i]!=fa) DFS(to[i],u), f[u]-=f[to[i]], siz[u]+=siz[to[i]];
}

void D2(int u,int fa) {
	eF(i,u) if(to[i]!=fa) {
		D2(to[i],u);
		Ans=((Ans+(ll)f[to[i]]*siz[to[i]]%Mod*val[u]%Mod)%Mod+Mod)%Mod;
	}
	if(fa!=0) Ans=((Ans+(ll)(((dep[u]&1)?-f[1]:f[1])+f[u])*(n-siz[u])%Mod*val[u]%Mod)%Mod+Mod)%Mod;
}

int main() {
	int x,y;
	scanf("%d",&n);
	F(i,1,n) scanf("%d",val+i);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1,0);
	F(i,1,n) if(dep[i]&1) Ans+=(ll)f[1]*val[i];
	else Ans-=(ll)f[1]*val[i];
	Ans=(Ans%Mod+Mod)%Mod;
	Ans=Ans*n%Mod;
	D2(1,0);
	printf("%lld\n",Ans);
	return 0;
}