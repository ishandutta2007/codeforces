#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[100010],B[100010];
bool wa[100010],wb[100010];
int fir[100010],dis[200010],nxt[200010],w[200010],del[200010],id=1;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int F[2][2],f[100010][2][2][2];
int vis[100010],tm=1;
int Path[100010],o,lnk[100010],loop[100010];
int dfs(int x,int fa,int d){
	vis[x]=tm;if(d)Path[++o]=x;
	for(int i=fir[x];i;i=nxt[i])
		if(vis[dis[i]]<tm&&del[i]<tm){
			del[i]=del[i^1]=tm;
			lnk[o]=w[i];
			int ret=dfs(dis[i],x,d);
			return ret;
		}
	return x;
}
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i){
		int o=gi();
		A[i]=gi();if(A[i]<0)wa[i]=1,A[i]*=-1;
		if(o==2){
			B[i]=gi();if(B[i]<0)wb[i]=1,B[i]*=-1;
			link(A[i],B[i],i),link(B[i],A[i],i);
		}else link(A[i],A[i],i),link(A[i],A[i],i),loop[A[i]]=i;
	}
	int mul=1;
	F[0][0]=1;int t=0;
	for(int s=1;s<=m;++s){
		if(vis[s])continue;
		o=0;
		int p1=dfs(s,-1,0);++tm;
		dfs(p1,-1,1);
		if(o==1){
			int p=w[fir[s]];
			if(!fir[s])mul=2*mul%mod;
			else if(nxt[nxt[fir[s]]]){
				int p2=w[nxt[nxt[fir[s]]]];
				if(wa[p]==wa[p2])mul=2*mul%mod;
				else std::swap(F[t][0],F[t][1]),F[t][0]=2*F[t][0]%mod,F[t][1]=2*F[t][1]%mod;
			}else if(A[p]==B[p]&&wa[p]!=wb[p])std::swap(F[t][0],F[t][1]),F[t][0]=2*F[t][0]%mod,F[t][1]=2*F[t][1]%mod;
			else{
				int s=(F[t][0]+F[t][1])%mod;
				F[t][0]=F[t][1]=s;
			}
			continue;
		}
		memset(f,0,(o+1)*sizeof(f[0]));
		f[1][0][0][0]=f[1][1][0][1]=1;
		lnk[o]=0;
		for(int i=fir[Path[1]];i;i=nxt[i])if(dis[i]==Path[o])lnk[o]=w[i];
		if(lnk[o]==lnk[1]||!lnk[o])lnk[o]=-1;
		if(loop[Path[1]])lnk[0]=loop[Path[1]];else lnk[0]=-1;
		if(loop[Path[o]])lnk[o+1]=loop[Path[o]];else lnk[o+1]=-1;
		for(int i=1;i<o;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					for(int l=0;l<2;++l){
						if(!f[i][j][k][l])continue;
						for(int nj=0;nj<2;++nj){
							int nk=k,p=lnk[i];
							bool di=j^(Path[i]==A[p]?wa[p]:wb[p]),dj=nj^(Path[i+1]==A[p]?wa[p]:wb[p]);
							if(di|dj)nk^=1;
							add(f[i+1][nj][nk][l],f[i][j][k][l]);
						}
					}
		memset(F[!t],0,sizeof F[!t]);
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l){
					if(!f[o][j][k][l])continue;
					int p=lnk[o],kk=k;
					if(~p){
						bool di=l^(Path[1]==A[p]?wa[p]:wb[p]),dj=j^(Path[o]==A[p]?wa[p]:wb[p]);
						if(di|dj)kk^=1;
					}
					if(~(p=lnk[0]))if(l^wa[p])kk^=1;
					if(~(p=lnk[o+1]))if(j^wa[p])kk^=1;
					for(int i=0;i<2;++i)add(F[!t][i^kk],1ll*F[t][i]*f[o][j][k][l]%mod);
				}
		t^=1;
	}
	printf("%d\n",1ll*mul*F[t][1]%mod);
	return 0;
}