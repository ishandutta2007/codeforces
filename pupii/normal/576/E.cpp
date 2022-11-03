#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct dsu{
	int fa[500010],sz[500010];bool w[500010];
	std::stack<std::pair<int,int>>stk;
	int hd(int x){while(x^fa[x])x=fa[x];return x;}
	bool W(int x){bool r=0;while(x^fa[x])r^=w[x],x=fa[x];return r;}
	int Union(int x,int y){
		int wx=W(x),wy=W(y);
		x=hd(x),y=hd(y);
		if(x==y)return 0;
		if(sz[x]>sz[y])std::swap(x,y);
		fa[x]=y,sz[y]+=sz[x];w[x]=wx^wy^1;
		stk.push({x,y});
		return 1;
	}
	void Undo(int t=1){
		while(t--){
			int x=stk.top().first,y=stk.top().second;
			stk.pop();
			sz[y]-=sz[x],fa[x]=x;w[x]=0;
		}
	}
	void pre(int n){for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;}
}set[50];
int n,m,k,q;
int eA[500010],eB[500010],qE[500010],qC[500010],qR[500010],lst[500010],col[500010];
std::vector<int>vec[2000010];
#define mid ((l+r)>>1)
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return vec[x].push_back(d);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
}
void divide(int x,int l,int r){
	int s[50]={0};
	for(int i:vec[x])if(~qC[i])s[qC[i]]+=set[qC[i]].Union(eA[qE[i]],eB[qE[i]]);
	if(l==r){
		int a=eA[qE[l]],b=eB[qE[l]];
		if(set[qC[l]].hd(a)==set[qC[l]].hd(b)&&set[qC[l]].W(a)==set[qC[l]].W(b))puts("NO"),qC[l]=col[qE[l]];
		else puts("YES"),col[qE[l]]=qC[l];
		update(1,1,q,l+1,qR[l],l);
	}else divide(x<<1,l,mid),divide(x<<1|1,mid+1,r);
	for(int i=0;i<50;++i)set[i].Undo(s[i]);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),k=gi(),q=gi();
	for(int i=0;i<k;++i)set[i].pre(n);
	for(int i=1;i<=m;++i)eA[i]=gi(),eB[i]=gi();
	for(int i=1;i<=q;++i)qE[i]=gi(),qC[i]=gi()-1;
	for(int i=1;i<=m;++i)lst[i]=q;
	for(int i=q;i;--i)qR[i]=lst[qE[i]],lst[qE[i]]=i-1;
	memset(col,-1,sizeof col);
	divide(1,1,q);
	return 0;
}