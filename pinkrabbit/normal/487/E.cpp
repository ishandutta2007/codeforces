#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<set>
#define Fv(H,A,X) for(int A=H[X];A;A=e[A].nxt)
/*
CF487E Tourists



 

 
*/

std::multiset<int> s[200005]; 

const int INF=2147483647;

inline int Max(int A,int B){
	return A>B?A:B;
}
inline int Min(int A,int B){
	return A<B?A:B;
}
inline void Swap(int &A,int &B){
	A^=B^=A^=B;
}

struct ee{
	int v;
	int nxt;
}e[2000005];
int h0[100005],h[200005],et=0;
inline void Eadd(int *H,int U,int V){
	e[++et]=(ee){V,H[U]};
	H[U]=et;
}
inline void add(int *H,int U,int V){
	Eadd(H,U,V);
	Eadd(H,V,U);
}


int dfn[200005],lw[100005];
// 
int nm,cnt=0;
int st[100005],tp=0;
inline void dfs0(int X){
	dfn[X]=lw[X]=++cnt;
	st[++tp]=X;
	Fv(h0,i,X){
		if(!dfn[e[i].v]){
			dfs0(e[i].v);
			lw[X]=Min(lw[X],lw[e[i].v]);
			if(lw[e[i].v]==dfn[X]){
				++nm;
				for(int j=0;j!=e[i].v;--tp){
					j=st[tp];
					add(h,nm,j);
				}
				add(h,X,nm);
			}
		}else{
			lw[X]=Min(lw[X],dfn[e[i].v]);
		}
	}
}
int fa[200005],sz[200005],dep[200005],son[200005],top[200005],loc[200005];
inline void dfs1(int X,int FA){
	fa[X]=FA,dep[X]=dep[FA]+1,sz[X]=1;
	Fv(h,i,X){
		if(e[i].v!=FA){
			dfs1(e[i].v,X);
			sz[X]+=sz[e[i].v];
			if(sz[son[X]]<sz[e[i].v]){
				son[X]=e[i].v;
			}
		}
	}
}
inline void dfs2(int X,int FA,int TP){
	dfn[X]=++cnt,loc[cnt]=X,top[X]=TP;
	if(son[X]){
		dfs2(son[X],X,TP);
	}
	Fv(h,i,X){
		if(e[i].v!=FA&&e[i].v!=son[X]){
			dfs2(e[i].v,X,e[i].v);
		}
	}
}

int n,m,q;
int a[200005];

#define MID (L+R>>1)
#define LS (X<<1)
#define RS (X<<1|1)

int tr[600005];
inline void bld(int X,int L,int R){
	if(L==R){
		tr[X]=a[loc[L]];
//		 
		return;
	}
	bld(LS,L,MID);
	bld(RS,MID+1,R);
	tr[X]=Min(tr[LS],tr[RS]);
}

inline void chg(int X,int L,int R,int P,int V){
	if(L==R){
		tr[X]=V;
		return;
	}
	P<=MID?chg(LS,L,MID,P,V):chg(RS,MID+1,R,P,V);
	tr[X]=Min(tr[LS],tr[RS]);
}

inline int qry(int X,int L,int R,int A,int B){
	if(A>R||L>B){
		return INF;
	}
	if(A<=L&&R<=B){
		return tr[X];
	}
	return Min(qry(LS,L,MID,A,B),qry(RS,MID+1,R,A,B));
}

void init(){
	scanf("%d%d%d",&n,&m,&q);
	nm=n;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		add(h0,u,v);
	}
	dfs0(1);
	dfs1(1,0);
	cnt=0;
	dfs2(1,0,1);
	for(int i=1;i<=n;++i){
		if(fa[i]){
			s[fa[i]].insert(a[i]);
		}
	}
	for(int i=n+1;i<=nm;++i){
		a[i]=*s[i].begin();
	}
	bld(1,1,nm);
	char ch[3];
	int x,y;
	int ans;
	for(int i=1;i<=q;++i){
		std::cin>>ch;
		scanf("%d%d",&x,&y);
		if(ch[0]=='C'){
			chg(1,1,nm,dfn[x],y);
			if(fa[x]){
				u=fa[x];
				s[u].erase(s[u].lower_bound(a[x]));
				s[u].insert(y);
				if(a[u]!=*s[u].begin()){
					a[u]=*s[u].begin();
					chg(1,1,nm,dfn[u],a[u]);
				}
			}
			a[x]=y;
		}else{
			ans=INF;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]){
					Swap(x,y);
				}
				ans=Min(ans,qry(1,1,nm,dfn[top[x]],dfn[x]));
				x=fa[top[x]];
			}
			if(dfn[x]>dfn[y]){
				Swap(x,y);
			}
			ans=Min(ans,qry(1,1,nm,dfn[x],dfn[y]));
			if(x>n){
				ans=Min(ans,a[fa[x]]);
			}
			printf("%d\n",ans);
		}
	} 
}

int main(){
	init();
	return 0;
}