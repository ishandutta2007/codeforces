#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,N,mod,num[110][110],yes[11000];
char map[110][110];
int fa[11000];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int fir[11000],dis[100010],nxt[100010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int FA[11000],qaq[11000],A[410][410];
int cxk(int O){
	int cir=0,c=0;memset(A,0,sizeof A);
	for(int o=0;o<3;++o){
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j){
				if((o>0)^(map[i][j]=='*'))continue;
				int a=-1,b=-1;
				if(map[i][j]!='/'){if(yes[num[i][j]]==O)a=num[i][j],b=num[i+1][j+1];}
				if(map[i][j]!='\\'){if(yes[num[i+1][j]]==O)a=num[i+1][j],b=num[i][j+1];}
				if(~a){
					a=hd(a),b=hd(b);
					if(a>b)std::swap(a,b);
					if(a==b)cir=1;
					if(o==1){
						a=qaq[FA[a]],b=qaq[FA[b]];
						++A[a][a],++A[b][b];
						--A[b][a],--A[a][b];
					}else fa[b]=a;
				}
			}
		if(!o&&cir)return 0;
		if(!o)
			for(int i=1;i<=N;++i){
				FA[i]=fa[i];
				if(yes[i]==O&&fa[i]==i)qaq[i]=++c;
			}
	}
	for(int i=1,j=-1;i<=N;++i)
		if(yes[i]==O){
			if(~j){if(hd(i)!=j)return 0;}
			else j=i;
		}
	--c;
	for(int i=1;i<=c;++i)
		for(int j=1;j<=c;++j)
			A[i][j]=(A[i][j]%mod+mod)%mod;
	int qwq=1;
	for(int i=1;i<=c;++i)
		for(int j=i+1;j<=c;++j){
			while(A[j][i]){
				int a=A[i][i]/A[j][i];
				for(int k=c;k>=i;--k)A[i][k]=(A[i][k]-1ll*a*A[j][k]%mod+mod)%mod;
				if(A[j][i])std::swap(A[i],A[j]),qwq=mod-qwq;
			}
		}
	for(int i=1;i<=c;++i)qwq=1ll*qwq*A[i][i]%mod;
	return qwq;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi()+1,m=gi()+1,mod=gi();
	for(int i=1;i<n;++i)scanf("%s",map[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			num[i][j]=++N,yes[N]=i+j&1;
	for(int i=1;i<=N;++i)fa[i]=i;
	printf("%d\n",(cxk(0)+cxk(1))%mod);
	return 0;
}