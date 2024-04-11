#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5;
int n;
char s[maxn];
int sz=1,last=0,len[maxn*2],link[maxn*2],nxt[maxn*2][26];
vector<int> ch[maxn*2];
void extend(int c){
	int cur=sz++;
	len[cur]=len[last]+1;
	int p=last;
	while(p>=0&&!nxt[p][c]){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p>=0){
		int q=nxt[p][c];
		if(len[p]+1==len[q]) link[cur]=q;
		else{
			int clone=sz++;
			link[clone]=link[q];
			memcpy(nxt[clone],nxt[q],sizeof(nxt[0]));
			len[clone]=len[p]+1;
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[cur]=link[q]=clone;
		}
	}
	last=cur;
}
int cur[maxn];
int size[maxn*2],hson[maxn*2];
void dfs1(int u){
	size[u]=1;
	hson[u]=-1;
	for(int v:ch[u]){
		dfs1(v);
		size[u]+=size[v];
		if(hson[u]<0||size[v]>size[hson[u]]) hson[u]=v;
	}
}
int top[maxn*2],pos[maxn*2];
vector<int> f;
void dfs2(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(hson[u]<0) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:ch[u]){
		if(v==hson[u]) continue;
		top[v]=v;
		dfs2(v);
	}
}
int get(int u,int l){
	while(top[u]&&len[link[top[u]]]>=l) u=link[top[u]];
	int lb=pos[top[u]],rb=pos[u];
	while(lb<rb){
		int mid=lb+(rb-lb)/2;
		if(len[f[mid]]>=l) rb=mid;
		else lb=mid+1;
	}
	return f[rb];
}
struct node{
	int l,r;
	node* ch[2];
	int mx;
	node(int l,int r):l(l),r(r),mx(0){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,int k){
		mx=max(mx,k);
		if(l==r) return;
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return mx;
		int ans=0;
		if(ql<=ch[0]->r) ans=max(ans,ch[0]->query(ql,qr));
		if(qr>=ch[1]->l) ans=max(ans,ch[1]->query(ql,qr));
		return ans;
	}
}*rt;
int dp[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",s+1);
	link[0]=-1;
	for(int i=n;i>0;i--){
		extend(s[i]-'a');
		cur[i]=last;
	}
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	dfs1(0);
	dfs2(0);
	rt=new node(0,sz-1);
	dp[n+1]=0;
	for(int i=n;i>0;i--) for(dp[i]=dp[i+1]+1;;dp[i]--){
		rt->modify(pos[cur[i+dp[i]]],dp[i+dp[i]]);
		int u=get(cur[i],dp[i]-1);
		if(rt->query(pos[u],pos[u]+size[u]-1)>=dp[i]-1) break;
		u=get(cur[i+1],dp[i]-1);
		if(rt->query(pos[u],pos[u]+size[u]-1)>=dp[i]-1) break;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}