#include<bits/stdc++.h>
#define mo1 1000000007
typedef unsigned long long ull;
int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char s[300010];
int fir[300010],dis[600010],nxt[600010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
struct HASH{int a;unsigned b;}Base[600010],iBase[600010],HS[300010],RHS[300010];
HASH operator+(HASH A,HASH B){return{A.a+B.a>=mo1?A.a+B.a-mo1:A.a+B.a,A.b+B.b};}
HASH operator-(HASH A,HASH B){return{A.a>=B.a?A.a-B.a:A.a+mo1-B.a,A.b-B.b};}
HASH operator*(HASH A,HASH B){return{1ll*A.a*B.a%mo1,A.b*B.b};}
bool operator==(HASH A,HASH B){return A.a==B.a&&A.b==B.b;}
int fa[300010],dep[300010],st[19][300010],mxlen[300010],son[300010],top[300010];
std::vector<int>up[300010];
void dfs(int x){
	HASH now={s[x]-'a'+1,s[x]-'a'+1};
	HS[x]=(HS[x]+now)*Base[1];
	RHS[x]=RHS[x]+now*Base[dep[x]];
	mxlen[x]=dep[x];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		dep[dis[i]]=dep[x]+1;
		fa[dis[i]]=st[0][dis[i]]=x;
		HS[dis[i]]=HS[x];
		RHS[dis[i]]=RHS[x];
		dfs(dis[i]);
		mxlen[x]=std::max(mxlen[dis[i]],mxlen[x]);
		if(mxlen[son[x]]<mxlen[dis[i]])son[x]=dis[i];
	}
}
int lg[300010],dfn[300010],end[300010],dfns[300010];
void dfs(int x,int tp){
	top[x]=tp;dfn[x]=++dfn[0];end[x]=dfn[0];dfns[dfn[0]]=x;
	if(son[x])dfs(son[x],tp),end[x]=end[son[x]];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i]||son[x]==dis[i])continue;
		dfs(dis[i],dis[i]);
	}
	if(tp==x){
		up[x].resize(std::min(end[x]-dfn[x]+1,dep[x]));
		int y=x,i=0;
		while(i<up[x].size()&&y)up[x][i]=y,++i,y=fa[y];
		up[x].resize(i);
	}
}
int LCA(int a,int b){
	if(dep[a]<dep[b])std::swap(a,b);
	int c=dep[a]-dep[b];
	for(int i=18;~i;--i)if((c>>i)&1)a=st[i][a];
	for(int i=18;~i;--i)if(st[i][a]^st[i][b])a=st[i][a],b=st[i][b];
	if(a^b)a=st[0][a];return a;
}
int jump(int x,int k){
	if(!k)return x;
	int y=top[st[lg[k]][x]];
	if(dep[x]-k>=dep[y])return dfns[dfn[y]+dep[x]-k-dep[y]];
	else return up[y][k-dep[x]+dep[y]];
}
HASH getHS(int x,int y,int l,int k){
	if(dep[x]-dep[l]+1>=k){
		int p=jump(x,k-1);
		return HS[x]-HS[fa[p]]*Base[dep[x]-dep[p]+1];
	}else{
		int p=jump(y,dep[y]-k+dep[x]-2*dep[l]+1);
		return HS[x]-HS[fa[l]]*Base[dep[x]-dep[l]+1]+(RHS[p]-RHS[l])*(dep[x]+1>=2*dep[l]?Base[dep[x]-2*dep[l]+1]:iBase[2*dep[l]-dep[x]-1]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;scanf("%s",s+1);
	Base[0]={1,1},Base[1]={127,23333};
	for(int i=2;i<=2*n;++i)Base[i]=Base[i-1]*Base[1];
	iBase[0]={1,1},iBase[1]={480314964,2208319661};
	for(int i=2;i<=2*n;++i)iBase[i]=iBase[i-1]*iBase[1];
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	dep[1]=1;dfs(1);dfs(1,1);
	for(int i=1;i<19;++i)
		for(int j=1;j<=n;++j)
			st[i][j]=st[i-1][st[i-1][j]];
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	int Q=gi();
	while(Q--){
		int xa=gi(),xb=gi(),ya=gi(),yb=gi();
		int lx=LCA(xa,xb),ly=LCA(ya,yb);
		int l=0,r=std::min(dep[xa]+dep[xb]-2*dep[lx],dep[ya]+dep[yb]-2*dep[ly])+1,mid;
		while(l<r){
			mid=((l+r)>>1)+1;
			(getHS(xa,xb,lx,mid)==getHS(ya,yb,ly,mid))?l=mid:r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}