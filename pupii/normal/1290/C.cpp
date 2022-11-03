#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>vec[300010];
int fir[300010],dis[1200010],nxt[1200010],w[1200010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int fa[300010],wl[300010],wr[300010],col[300010];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
void dfs(int x){for(int i=fir[x];i;i=nxt[i])if(col[dis[i]]==-1)col[dis[i]]=col[x]^w[i],dfs(dis[i]);}
char s[300010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	scanf("%s",s+1);
	for(int i=1;i<=m;++i){
		int c=gi();
		while(c--)vec[gi()].push_back(i);
	}
	for(int i=1;i<=n;++i)
		if(vec[i].size()==2)
			link(vec[i][0],vec[i][1],'1'-s[i]),
			link(vec[i][1],vec[i][0],'1'-s[i]);
	memset(col,-1,sizeof col);
	for(int i=1;i<=m;++i)if(col[i]==-1)col[i]=0,dfs(i);
	for(int i=1;i<=m;++i)
		if(col[i]==0)fa[i]=i,wl[i]=1;
		else fa[i]=i,wr[i]=1;
	int ans=0;
	for(int i=1,a,b,A,B;i<=n;++i){
		if(vec[i].size()==1){
			a=vec[i][0];A=hd(a);
			ans-=std::min(wl[A],wr[A]);
			if(col[a]==s[i]-'0')wr[A]=1919810;
			else wl[A]=1919810;
			ans+=std::min(wl[A],wr[A]);
		}else if(vec[i].size()==2){
			a=vec[i][0],b=vec[i][1];
			A=hd(a),B=hd(b);
			if(A!=B){
				ans-=std::min(wl[A],wr[A]);
				ans-=std::min(wl[B],wr[B]);
				fa[A]=B;
				wl[B]=std::min(1919810,wl[B]+wl[A]);
				wr[B]=std::min(1919810,wr[B]+wr[A]);
				ans+=std::min(wl[B],wr[B]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}