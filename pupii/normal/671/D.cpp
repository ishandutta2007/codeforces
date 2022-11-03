#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[300010],dis[600010],nxt[600010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
std::vector<int>ins[300010],del[300010];
int W[300010],tag[300010],ch[300010][2],fa[300010];
void upd(int x,int d){if(x)W[x]-=d,tag[x]+=d;}
void down(int x){if(x)upd(ch[x][0],tag[x]),upd(ch[x][1],tag[x]),tag[x]=0;}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(W[x]>W[y])std::swap(x,y);
	down(x);
	ch[x][1]=merge(ch[x][1],y);
	std::swap(ch[x][0],ch[x][1]);
	fa[ch[x][0]]=fa[ch[x][1]]=x;
	return x;
}
ll ans;
int dfs(int x,int FA=-1){
	int rt=0;
	for(int i:ins[x])rt=merge(rt,i);
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==FA)continue;
		rt=merge(rt,dfs(dis[i],x));
		fa[rt]=0;
	}
	for(int i:del[x]){
		if(i==rt)rt=merge(ch[i][0],ch[i][1]);
		else{
			int f=fa[i];down(i);
			ch[f][i==ch[f][1]]=merge(ch[i][0],ch[i][1]);
			fa[ch[f][0]]=fa[ch[f][1]]=f;
		}
	}
	if(rt)ans+=W[rt],upd(rt,W[rt]);
	else if(x>1)puts("-1"),exit(0);
	return rt;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	for(int i=1;i<=m;++i)a=gi(),b=gi(),W[i]=gi(),ins[a].push_back(i),del[b].push_back(i);
	dfs(1);printf("%lld\n",ans);
	return 0;
}