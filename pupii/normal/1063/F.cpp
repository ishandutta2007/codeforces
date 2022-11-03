#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n;
int st[20][1000010];
std::vector<int>G[1000010];
int dfn[1000010],siz[1000010];
namespace SAM{
	int slink[1000010],trans[1000010][26],len[1000010],endpos[1000010],cnt,lst,leaf[1000010],flg,yes[1000010];
	struct _init{_init(){cnt=0;lst=++cnt;len[lst]=0;}}__init;
	il vd dfs(int x){
		dfn[x]=endpos[x]?++dfn[0]:dfn[0]+1;
		siz[x]=endpos[x];
		for(int i:G[x])dfs(i),siz[x]+=siz[i];
	}
	il vd extend(int ch,int i){
		int p=lst,np=++cnt;len[np]=len[p]+1;lst=np;endpos[np]=1;leaf[i]=np;
		while(p&&!trans[p][ch])trans[p][ch]=np,p=slink[p];
		if(!p)slink[np]=1;
		else{
			int q=trans[p][ch];
			if(len[q]==len[p]+1)slink[np]=q;
			else{
				int nq=++cnt;
				slink[nq]=slink[q],len[nq]=len[p]+1,memcpy(trans[nq],trans[q],sizeof trans[q]);
				while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
				slink[np]=slink[q]=nq;
			}
		}
	}
	int t[1000010],srt[1000010];
	il vd prepare(){
		for(int i=1;i<=cnt;++i)G[slink[i]].push_back(i);
		dfs(1);
		for(int i=1;i<=cnt;++i)++t[len[i]];
		for(int i=1;i<=cnt;++i)t[i]+=t[i-1];
		for(int i=cnt;i>1;--i)srt[t[len[i]]--]=i;
		for(int i=cnt,x;i;--i)if(slink[srt[i]])x=srt[i],endpos[slink[x]]+=endpos[x];
		for(int i=1;i<=cnt;++i)st[0][i]=slink[i];
		for(int i=1;i<20;++i)
			for(int j=1;j<=cnt;++j)
				st[i][j]=st[i-1][st[i-1][j]];
	}
}
int mx[2000010];
#define mid ((l+r)>>1)
il vd update(int x,int l,int r,const int&p,const int&d){
	if(d>mx[x])mx[x]=d;if(l==r)return;
	if(p<=mid)update(x<<1,l,mid,p,d);
	else update(x<<1|1,mid+1,r,p,d);
}
il int query(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return mx[x];
	if(L<=mid)
		if(mid<R)return std::max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
		else return query(x<<1,l,mid,L,R);
	else return query(x<<1|1,mid+1,r,L,R);
}
#undef mid
char S[500010];
int f[500010],p;
il bool check(int i,int F){
	if(F==1)return 1;
	while(p<i-F)++p,update(1,1,n,dfn[SAM::leaf[p]],f[p]);
	int x=SAM::leaf[i-1];
	for(int j=19;~j;--j)if(st[j][x]&&SAM::len[st[j][x]]>=F-1)x=st[j][x];
	if(query(1,1,n,dfn[x],dfn[x]+siz[x]-1)>=F-1)return 1;
	x=SAM::leaf[i];
	for(int j=19;~j;--j)if(st[j][x]&&SAM::len[st[j][x]]>=F-1)x=st[j][x];
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1)>=F-1;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();scanf("%s",S+1);
	std::reverse(S+1,S+n+1);
	for(int i=1;i<=n;++i)SAM::extend(S[i]-'a',i);
	SAM::prepare();
	int ans=0;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+1;
		while(!check(i,f[i]))--f[i];
		if(f[i]>ans)ans=f[i];
	}
	printf("%d\n",ans);
	return 0;
}