#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[200010];
int trans[400010][26],len[400010],slink[400010],leaf[200010],lst=1,cnt=1,C;
int st[400010],tt[400010],root[400010],f[400010],g[400010],endpos[400010];
void extend(int ch,int i){
	int p=lst,np=++cnt;lst=np;len[np]=len[p]+1;leaf[i]=np;endpos[np]=i;
	while(p&&!trans[p][ch])trans[p][ch]=np,p=slink[p];
	if(!p)slink[np]=1;
	else{
		int q=trans[p][ch];
		if(len[q]==len[p]+1)slink[np]=q;
		else{
			int nq=++cnt;
			len[nq]=len[p]+1;slink[nq]=slink[q];memcpy(trans[nq],trans[q],4*26);
			while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
			slink[np]=slink[q]=nq;
		}
	}
}
int ls[10000010],rs[10000010];
#define mid ((l+r)>>1)
void build(int&x,int l,int r,const int&p){
	x=++cnt;if(l==r)return;
	if(p<=mid)build(ls[x],l,mid,p);
	else build(rs[x],mid+1,r,p);
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	int o=++cnt;
	ls[o]=merge(ls[x],ls[y]);
	rs[o]=merge(rs[x],rs[y]);
	return o;
}
bool query(int x,int l,int r,const int&L,const int&R){
	if(!x)return 0;
	if(L<=l&&r<=R)return 1;
	if(L<=mid)
		if(mid<R)return query(ls[x],l,mid,L,R)||query(rs[x],mid+1,r,L,R);
		else return query(ls[x],l,mid,L,R);
	else return query(rs[x],mid+1,r,L,R);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%s",S+1);
	for(int i=1;i<=n;++i)extend(S[i]-='a',i);
	C=cnt;cnt=0;
	for(int i=1;i<=C;++i)++tt[len[i]];
	for(int i=1;i<=n;++i)tt[i]+=tt[i-1];
	for(int i=C;i;--i)st[tt[len[i]]--]=i;
	for(int i=1;i<=n;++i)build(root[leaf[i]],1,n,i);
	for(int _=C,x;_>1;--_)x=st[_],root[slink[x]]=merge(root[slink[x]],root[x]),endpos[slink[x]]=endpos[x];
	int ans=0;
	f[1]=1;
	for(int _=2,x;_<=C;++_){
		x=st[_];
		if(len[x]==1||slink[x]==1)f[x]=1,g[x]=x;
		else if(query(root[g[slink[x]]],1,n,endpos[x]-len[x]+len[g[slink[x]]],endpos[x]-1))
			f[x]=f[slink[x]]+1,g[x]=x;
		else f[x]=f[slink[x]],g[x]=g[slink[x]];
		ans=std::max(ans,f[x]);
	}
	printf("%d\n",ans);
	return 0;
}