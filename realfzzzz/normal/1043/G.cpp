#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=2e5+5;
int n,q,l[maxn],r[maxn];
char S[maxn];
struct SAM{
	int sz=1,last=0,len[maxn*2],link[maxn*2],nxt[maxn*2][26];
	vector<int> g[maxn*2];
	SAM(){
		link[0]=-1;
	}
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
			if(len[q]==len[p]+1) link[cur]=q;
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
	int dep[maxn*2],size[maxn*2],hson[maxn*2];
	void dfs1(int u){
		dep[u]=u?dep[link[u]]+1:1;
		size[u]=1;
		hson[u]=-1;
		for(int v:g[u]){
			dfs1(v);
			size[u]+=size[v];
			if(hson[u]<0||size[v]>size[hson[u]]) hson[u]=v;
		}
	}
	int pos[maxn*2],top[maxn*2],pos2[maxn*2];
	vector<int> f,f2;
	void dfs2(int u){
		pos[u]=f.size();
		f.push_back(u);
		pos2[u]=f2.size();
		f2.push_back(u);
		if(hson[u]<0) return;
		top[hson[u]]=top[u];
		dfs2(hson[u]);
		f2.push_back(u);
		for(int v:g[u]){
			if(v==hson[u]) continue;
			top[v]=v;
			dfs2(v);
			f2.push_back(u);
		}
	}
	int st[25][maxn*4],lg[maxn*4];
	void build(){
		for(int i=0;i<sz*2-1;i++) st[0][i]=i;
		for(int i=1;(1<<i)-1<sz*2-1;i++)
			for(int j=0;j+(1<<i)-1<sz*2-1;j++)
				if(dep[f2[st[i-1][j]]]<dep[f2[st[i-1][j+(1<<(i-1))]]])
					st[i][j]=st[i-1][j];
				else st[i][j]=st[i-1][j+(1<<(i-1))];
		for(int i=2;i<=sz*2-1;i++) lg[i]=lg[i/2]+1;
	}
	int query(int l,int r){
		int k=lg[r-l+1];
		if(dep[f2[st[k][l]]]<dep[f2[st[k][r-(1<<k)+1]]]) return st[k][l];
		else return st[k][r-(1<<k)+1];
	}
	int lca(int x,int y){
		if(pos2[x]>pos2[y]) swap(x,y);
		return f2[query(pos2[x],pos2[y])];
	}
}t1,t2;
int cur1[maxn],cur2[maxn];
struct item{
	int x,u;
	bool type;
	bool operator <(const item b)const{
		if(x<0||b.x<0) return x<0&&b.x>=0;
		return type?l[x]+t1.len[u]<l[b.x]+t1.len[b.u]:l[x]<l[b.x];
	}
};
struct node{
	int l,r;
	node* ch[2];
	item v;
	priority_queue<item> pq;
	void pushup(){
		v=max(ch[0]->v,ch[1]->v);
	}
	node(int l,int r,bool type):l(l),r(r),v({-1,0,type}){
		if(l==r){
			pq.push({-1,0,type});
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid,type);
		ch[1]=new node(mid+1,r,type);
		pushup();
	}
	void modify(int x,item k){
		if(l==r){
			if(k.x>=0) pq.push(k);
			else pq.pop();
			v=pq.top();
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	item query(int ql,int qr){
		if(ql<=l&&qr>=r) return v;
		item ans={-1,0,v.type};
		if(ql<=ch[0]->r) ans=max(ans,ch[0]->query(ql,qr));
		if(qr>=ch[1]->l) ans=max(ans,ch[1]->query(ql,qr));
		return ans;
	}
}*rt1,*rt2;
vector<int> q1[maxn],q2[maxn];
int ans1[maxn],ans2[maxn];
void work(int x,int u,int* ans){
	while(u>=0){
		while(1){
			item res=rt1->query(t1.pos[u],t1.pos[u]+t1.size[u]-1);
			if(res.x<0||l[res.x]+t1.len[u]<=x) break;
			if(ans[res.x]<0) ans[res.x]=x-l[res.x]+1;
			rt1->modify(t1.pos[res.u],{-1,0,0});
		}
		while(1){
			item res=rt2->query(t1.pos[t1.top[u]],t1.pos[u]);
			if(res.x<0||l[res.x]+t1.len[res.u]<=x) break;
			if(ans[res.x]<0) ans[res.x]=x-l[res.x]+1;
			rt2->modify(t1.pos[res.u],{-1,0,1});
		}
		u=t1.link[t1.top[u]];
	}
}
vector<int> c1[maxn],c2[maxn],c3[maxn],c4[maxn];
int p1[maxn],p2[maxn];
int lcs(int x,int y){
	return t1.len[t1.lca(cur1[x],cur1[y])];
}
int lcp(int x,int y){
	if(x>n||y>n) return 0;
	return t2.len[t2.lca(cur2[x],cur2[y])];
}
int st[20][maxn],lg[maxn];
int query(int l,int r){
	int k=lg[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int s[26][maxn];
bool check1(int x){
	int len=r[x]-l[x]+1;
	for(int i=1;i*i<=len;i++) if(len%i==0){
		if(lcs(r[x],r[x]-i)>=len-i) return 1;
		if(i>1&&lcs(r[x],r[x]-len/i)>=len-len/i) return 1;
	}
	return 0;
}
bool check2(int x){
	if(l[x]+p1[l[x]]-1<=r[x]) return 1;
	if(r[x]-p2[r[x]]+1>=l[x]) return 1;
	if(ans2[x]*2<=r[x]-l[x]+1) return 1;
	return 0;
}
bool check3(int x){
	if(s[S[l[x]]-'a'][r[x]]-s[S[l[x]]-'a'][l[x]]) return 1;
	if(s[S[r[x]]-'a'][r[x]-1]-s[S[r[x]]-'a'][l[x]-1]) return 1;
	if(query(l[x],r[x])<=r[x]) return 1;
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",S+1);
	for(int i=1;i<=n;i++){
		t1.extend(S[i]-'a');
		cur1[i]=t1.last;
	}
	for(int i=1;i<t1.sz;i++) t1.g[t1.link[i]].push_back(i);
	t1.dfs1(0);
	t1.dfs2(0);
	t1.build();
	for(int i=n;i>0;i--){
		t2.extend(S[i]-'a');
		cur2[i]=t2.last;
	}
	for(int i=1;i<t2.sz;i++) t2.g[t2.link[i]].push_back(i);
	t2.dfs1(0);
	t2.dfs2(0);
	t2.build();
	for(int i=1;i*2<=n;i++) for(int j=0;i*(j+1)+1<=n;j++){
		int p=min(lcp(i*j+2,i*(j+1)+2),i-1),s=min(lcs(i*j+1,i*(j+1)+1),i);
		if(p+s<i) continue;
		c1[i*j+1-s+i*2].push_back(i*2);
		c2[i*(j+1)+p+2].push_back(i*2);
		c3[i*(j+1)+p-i*2+2].push_back(i*2);
		c4[i*j+1-s].push_back(i*2);
	}
	multiset<int> se;
	for(int i=1;i<=n;i++){
		for(int j:c1[i]) se.insert(j);
		for(int j:c2[i]) se.erase(se.find(j));
		p2[i]=se.size()?*se.begin():n+1;
	}
	multiset<int>().swap(se);
	for(int i=n;i>0;i--){
		for(int j:c3[i]) se.insert(j);
		for(int j:c4[i]) se.erase(se.find(j));
		p1[i]=se.size()?*se.begin():n+1;
	}
	for(int i=1;i<=n;i++) st[0][i]=i+p1[i]-1;
	for(int i=1;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) s[j][i]=s[j][i-1];
		s[S[i]-'a'][i]++;
	}
	q=readint();
	for(int i=1;i<=q;i++){
		l[i]=readint();
		r[i]=readint();
		q1[r[i]].push_back(i);
		q2[l[i]].push_back(i);
	}
	rt1=new node(0,t1.sz-1,0);
	rt2=new node(0,t1.sz-1,1);
	memset(ans2,-1,sizeof(ans2));
	for(int i=1;i<=n;i++){
		for(int j:q2[i]){
			int u=cur1[r[j]];
			rt1->modify(t1.pos[u],{j,u,0});
			while(u>=0){
				rt2->modify(t1.pos[u],{j,u,1});
				u=t1.link[t1.top[u]];
			}
		}
		work(i,cur1[i],ans2);
	}
	for(int i=1;i<=q;i++){
		bool flag=0;
		for(int j=0;j<26;j++) flag|=s[j][r[i]]-s[j][l[i]-1]>1;
		if(!flag) printf("-1\n");
		else if(check1(i)) printf("1\n");
		else if(check2(i)) printf("2\n");
		else if(check3(i)) printf("3\n");
		else printf("4\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}