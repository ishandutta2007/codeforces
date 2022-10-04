#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
int n,m;
int h[501],nxt[100001],to[100001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int used[501],ret[501];
int o,oo,ooo;
int stk[501],top,pos[501];
int fk[501][501];
bool use[100001];
int cnt;
void dfs(int u){
//	printf(" u: %d\n",u);
	used[u]=cnt; stk[++top]=u; pos[u]=top;
	eF(i,u){
		if(used[to[i]]==0) dfs(to[i]);
		else{if(used[to[i]]==cnt&&ret[to[i]]==0){/*printf("error : %d -> %d\n",u,to[i]);*/o=pos[to[i]]; return;}}
		if(o) return;
	} --top; ret[u]=1;
}
void dfs2(int u){
//	printf(" u: %d\n",u);
	used[u]=cnt;
	eF(i,u) if(!use[i]){
//		printf("%d -> %d\n",u,to[i]);
		if(used[to[i]]==0) dfs2(to[i]);
		else{if(used[to[i]]==cnt&&ret[to[i]]==0){/*printf("error : %d -> %d\n",u,to[i]);*/ooo=1; return;}}
		if(ooo) return;
	} ret[u]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	if(m-1>n*(n-1)/2) {puts("NO"); return 0;}
	if(m<=2) {puts("YES"); return 0;}
	int x,y;
	F(i,1,m) scanf("%d%d",&x,&y), ins(x,y), fk[x][y]=tot;
	F(i,1,n){
		o=0; top=0; cnt=i;
		if(!used[i]) dfs(i);
		if(o) {oo=1; break;}
	}
	if(!oo) {puts("YES"); return 0;}
//	F(i,o,top)
//		printf(",%d",stk[i]); puts("");
	F(i,o,top){
//		printf(" %d\n",stk[i]);
		memset(used,0,sizeof used);
		memset(ret,0,sizeof ret);
		ooo=0;
		if(i!=top) use[fk[stk[i]][stk[i+1]]]=1;
		else use[fk[stk[i]][stk[o]]]=1;
		F(j,1,n){
			cnt=j;
			if(used[j]==0) dfs2(j);
//			printf("%d %d %d\n",j,used[j],ooo);
//			puts("====");
			if(ooo) break;
		}
		if(!ooo) {puts("YES"); return 0;}
		if(i!=top) use[fk[stk[i]][stk[i+1]]]=0;
		else use[fk[stk[i]][stk[o]]]=0;
	} puts("NO");
	return 0;
}