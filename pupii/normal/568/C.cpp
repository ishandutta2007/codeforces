#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m;
char S[30];
int px[160010],py[160010];
char pa[160010],pb[160010];
int ans[210],fixp;
char ANS[210];
int fir[410],dis[4000010],nxt[4000010],id;
int _fir[410],_id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int nV[210],nC[210],cnt;
int dfn[410],low[410],stk[410],tp,SCC[410],ins[410];
void tarjan(int x){
	dfn[x]=low[x]=++dfn[0];stk[++tp]=x;ins[x]=tp;
	for(int i=fir[x];i;i=nxt[i])
		if(!dfn[dis[i]])tarjan(dis[i]),low[x]=std::min(low[x],low[dis[i]]);
		else if(ins[dis[i]])low[x]=std::min(low[x],dfn[dis[i]]);
	if(dfn[x]==low[x]){
		++SCC[0];
		while(ins[x])ins[stk[tp]]=0,SCC[stk[tp]]=SCC[0],--tp;
	}
}
bool CXK(){
	memcpy(fir,_fir,sizeof fir);id=_id;
	for(int i=1;i<=fixp;++i)if(ans[i])link(nV[i],nC[i]);else link(nC[i],nV[i]);
	memset(dfn,0,sizeof dfn);memset(SCC,0,sizeof SCC);
	for(int i=1;i<=cnt;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)if(SCC[nV[i]]==SCC[nC[i]])return 0;
	return 1;
}
bool YV[210],YC[210];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S);
	int L=strlen(S),c[2]={0};
	for(int i=0;i<L;++i)++c[S[i]=='C'];
	n=gi(),m=gi();
	for(int i=1;i<=m;++i){
		px[i]=gi(),scanf("%s",pa+i);
		py[i]=gi(),scanf("%s",pb+i);
	}
	if(!c[0]){
		for(int i=1;i<=m;++i)if(pa[i]=='C'&&pb[i]=='V')return puts("-1"),0;
		while(n--)putchar('a');
		return 0;
	}
	if(!c[1]){
		for(int i=1;i<=m;++i)if(pa[i]=='V'&&pb[i]=='C')return puts("-1"),0;
		while(n--)putchar('a');
		return 0;
	}
	for(int i=1;i<=n;++i)nV[i]=++cnt,nC[i]=++cnt;
	for(int i=1;i<=m;++i){
		int A=nV[px[i]],B=nC[px[i]];
		int C=nV[py[i]],D=nC[py[i]];
		if(pa[i]=='C')std::swap(A,B);
		if(pb[i]=='C')std::swap(C,D);
		link(A,C),link(D,B);
	}
	memcpy(_fir,fir,sizeof fir);_id=id;
	if(!CXK())return puts("-1"),0;
	static char lim[210];
	scanf("%s",lim+1);
	for(int i=1;i<=n;++i)if(S[lim[i]-'a']=='C')ans[i]=1;
	fixp=n;if(CXK())return printf("%s",lim+1),0;
	for(int i=1;i<=n;++i)ANS[i]=lim[i];
	int s=-1;
	for(int i=n;i;--i){
		fixp=i;
		int nV=99,nC=99;
		for(int j=L-1;j>lim[i]-'a';--j)if(S[j]=='V')nV=j;else nC=j;
		s=i;
		if(nV<nC){
			if(nV<99){ans[i]=0;if(CXK()){ANS[i]=nV+'a';break;}}
			if(nC<99){ans[i]=1;if(CXK()){ANS[i]=nC+'a';break;}}
		}else{
			if(nC<99){ans[i]=1;if(CXK()){ANS[i]=nC+'a';break;}}
			if(nV<99){ans[i]=0;if(CXK()){ANS[i]=nV+'a';break;}}
		}
		s=-1;
	}
	if(s==-1)return puts("-1"),0;
	int nV=99,nC=99;
	for(int j=L-1;~j;--j)if(S[j]=='V')nV=j;else nC=j;
	for(int i=s+1;i<=n;++i){
		fixp=i;
		ans[i]=nV>nC;
		if(!CXK())ans[i]^=1;
		ANS[i]='a'+(ans[i]?nC:nV);
	}
	printf("%s",ANS+1);
	return 0;
}