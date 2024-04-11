#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,q;
int p[200010],a[200010],pp[200010],lst[200010],Nxt[200010];
int fir[200010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int stk[200010],tp,pos[200010];
void dfs(int x){
	stk[++tp]=x;
	if(tp>=n)pos[x]=stk[tp-n+1];else pos[x]=m+1;
	for(int i=fir[x];i;i=nxt[i])dfs(dis[i]);
	--tp;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),q=gi();
	int l,r;
	for(int i=1;i<=n;++i)pp[p[i]=gi()]=i;
	for(int i=1;i<=m;++i)a[i]=gi();
	p[n+1]=p[1];
	for(int i=m;i;--i)link(Nxt[i]=lst[p[pp[a[i]]+1]],i),lst[a[i]]=i;
	tp=-1;dfs(0);
	for(int i=m-1;i;--i)pos[i]=std::min(pos[i],pos[i+1]);
	while(q--)l=gi(),r=gi(),putchar((pos[l]<=r)+'0');
	return 0;
}