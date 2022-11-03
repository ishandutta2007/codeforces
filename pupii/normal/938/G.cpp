// luogu-judger-enable-o2
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
int EA[400010],EB[400010],ED[400010],ES[400010],ET[400010],E;
std::map<std::pair<int,int>,int>st;
int QX[400010],QY[400010];
int fa[200010],sz[200010],W[200010];
std::stack<std::pair<int*,int>>stk;
std::vector<int>QAQ[800010];
il int hd(int&x){int r=0;while(x!=fa[x])r^=W[x],x=fa[x];return r;}
il int Union(int x,int y,int d){
	int wx=hd(x),wy=hd(y);
	if(x==y)return d^wx^wy;
	if(sz[x]<sz[y])std::swap(x,y),std::swap(wx,wy);
	stk.push({&fa[y],fa[y]});stk.push({&sz[x],sz[x]});stk.push({&W[y],W[y]});
	fa[y]=x,sz[x]+=sz[y];W[y]=wx^wy^d;
	return-1;
}
#define mid ((l+r)>>1)
il vd Update(int x,int l,int r,const int&L,const int&R,const int&i){
	if(L<=l&&r<=R)return QAQ[x].push_back(i);
	if(L<=mid)Update(x<<1,l,mid,L,R,i);
	if(mid<R)Update(x<<1|1,mid+1,r,L,R,i);
}
int p[30],ans[200010];
il vd insert(int*p,int s){
	for(int i=29;~i;--i)
		if((s>>i)&1){
			if(p[i])s^=p[i];
			else{p[i]=s;break;}
		}
}
il vd DFS(int x,int l,int r){
	int _p[30],__p[30];memcpy(__p,p,sizeof p);memcpy(_p,p,sizeof p);
	int o=0;
	for(int i:QAQ[x]){
		int w=Union(EA[i],EB[i],ED[i]);
		if(~w)insert(_p,w);
		else o+=3;
	}
	if(l==r){
		int d=hd(QX[l])^hd(QY[l]);
		for(int i=29;~i;--i)if((d>>i)&1)d^=_p[i];
		ans[l]=d;
	}else{
		memcpy(p,_p,sizeof _p);
		DFS(x<<1,l,mid);
		memcpy(p,_p,sizeof _p);
		DFS(x<<1|1,mid+1,r);
	}
	while(o--)*stk.top().first=stk.top().second,stk.pop();
	memcpy(p,__p,sizeof __p);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),now=0;
	for(int i=1;i<=m;++i)EA[i]=gi(),EB[i]=gi(),ED[i]=gi(),ES[i]=1,st[{EA[i],EB[i]}]=i;
	E=m;
	int q=gi(),o,x,y;
	while(q--){
		o=gi(),x=gi(),y=gi();
		if(o==1)++E,EA[E]=x,EB[E]=y,ED[E]=gi(),ES[E]=now+1,st[{x,y}]=E;
		else if(o==2)ET[st[{x,y}]]=now,st.erase({x,y});
		else ++now,QX[now]=x,QY[now]=y;
	}
	for(auto i:st)ET[i.second]=now;
	for(int i=1;i<=E;++i)if(ES[i]<=ET[i])Update(1,1,now,ES[i],ET[i],i);
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	if(now)DFS(1,1,now);
	for(int i=1;i<=now;++i)printf("%d\n",ans[i]);
	return 0;
}