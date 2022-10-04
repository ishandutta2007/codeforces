#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])

map<int,int> mp;
set<int> st;

int n,q,m,k;
int p[100005];

int h[100005],nxt[100005],to[100005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int d[100005];
int dfn[100005],idf[100005],dfc;
int lc[100005][17];

void DFS(int u){
	dfn[u]=++dfc; idf[dfc]=u;
	int chl=0;
	eF(i,u){
		lc[dfc][0]=d[u];
		d[to[i]]=d[u]+1;
		DFS(to[i]);
	}
}

inline int Qur(int l,int r){
	l=dfn[l], r=dfn[r]-1;
	int j=31-__builtin_clz(r-l+1);
	return min(lc[l][j],lc[r-(1<<j)+1][j]);
}

struct node{
	int mx1,mx2,mn1,mn2;
	node(int x=0,int y=0,int z=0,int w=0):mx1(x),mx2(y),mn1(z),mn2(w){}
}f[100005][17];
int tmp[10], t;
inline node operator+(node i,node j){
	node a;
	
	tmp[1]=i.mx1, tmp[2]=i.mx2, tmp[3]=j.mx1, tmp[4]=j.mx2;
	sort(tmp+1,tmp+5); t=unique(tmp+1,tmp+5)-tmp-1;
	F(k,1,t) tmp[k]=dfn[tmp[k]];
	sort(tmp+1,tmp+t+1);
	a.mx1=idf[tmp[t]], a.mx2=idf[tmp[t-1]];
	
	tmp[1]=i.mn1, tmp[2]=i.mn2, tmp[3]=j.mn1, tmp[4]=j.mn2;
	sort(tmp+1,tmp+5); t=unique(tmp+1,tmp+5)-tmp-1;
	F(k,1,t) tmp[k]=dfn[tmp[k]];
	sort(tmp+1,tmp+t+1);
	a.mn1=idf[tmp[1]], a.mn2=idf[tmp[2]];
	
	return a;
}

int main(){
	scanf("%d%d",&n,&q);
	F(i,2,n) scanf("%d",p+i), ins(p[i],i);
	DFS(1);
	
//	F(i,1,n) printf("%d, ",dfn[i]); puts("");
	
	F(j,1,16) F(i,1,n-(1<<j)){
		lc[i][j]=min(lc[i][j-1],lc[i+(1<<j-1)][j-1]);
	}
	
	F(i,1,n-1){
		if(dfn[i]<dfn[i+1])
			f[i][1]=node(i+1,i,i,i+1);
		else
			f[i][1]=node(i,i+1,i+1,i);
	}
	
	F(j,2,16) F(i,1,n-(1<<j)+1){
		f[i][j]=f[i][j-1]+f[i+(1<<j-1)][j-1];
	}
	
	F(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r==l+1){
			if(d[l] > d[r]) printf("%d %d\n",r,d[l]);
			else printf("%d %d\n",l,d[r]);
			continue;
		}
		int j=31-__builtin_clz(r-l+1);
		int lp=l, rp=r-(1<<j)+1;
		node a=f[lp][j]+f[rp][j];
//		printf("mx1:%d , mx2:%d , mn1:%d , mn2:%d\n",a.mx1,a.mx2,a.mn1,a.mn2);
		if(Qur(a.mn2,a.mx1) > Qur(a.mn1,a.mx2))
			printf("%d %d\n",a.mn1,Qur(a.mn2,a.mx1));
		else
			printf("%d %d\n",a.mx1,Qur(a.mn1,a.mx2));
	}
	return 0;
}