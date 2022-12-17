#include<algorithm>
#include<queue>
#include<cstring>
#include<cctype>
#include<cstdio>
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
const int maxn=1e5+5;
int n,m;
char *s[maxn],res[maxn];
int len[maxn];
int sz=1,nxt[maxn][26],fail[maxn];
vector<int> ch[maxn];
int insert(char* s,int l){
	int u=0;
	for(int i=0;i<l;i++){
		if(!nxt[u][s[i]-'a']) nxt[u][s[i]-'a']=sz++;
		u=nxt[u][s[i]-'a'];
	}
	return u;
}
void build(){
	queue<int> q;
	fail[0]=-1;
	for(int i=0;i<26;i++) if(nxt[0][i]){
		fail[nxt[0][i]]=0;
		q.push(nxt[0][i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
			if(nxt[u][i]){
				fail[nxt[u][i]]=nxt[fail[u]][i];
				q.push(nxt[u][i]);
			}
			else nxt[u][i]=nxt[fail[u]][i];
	}
	for(int i=1;i<sz;i++) ch[fail[i]].push_back(i);
}
int pos[maxn],size[maxn];
vector<int> f;
void dfs(int u){
	pos[u]=f.size();
	f.push_back(u);
	size[u]=1;
	for(int i=0;i<(int)ch[u].size();i++){
		int v=ch[u][i];
		dfs(v);
		size[u]+=size[v];
	}
}
int cur[maxn];
struct qry{
	int x,k,id;
	bool flag;
	qry(int x,int k,int id,bool flag)
	:x(x),k(k),id(id),flag(flag){}
	bool operator <(qry b){
		return x<b.x;
	}
};
vector<qry> q,q2[maxn];
typedef long long ll;
ll ans[maxn];
ll c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,ll k){
	while(x<=sz){
		c[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void solve1(){
	sort(q.begin(),q.end());
	int cc=0;
	for(int i=0;i<(int)q.size();i++){
		while(cc<q[i].x){
			cc++;
			modify(pos[cur[cc]],1);
			modify(pos[cur[cc]]+size[cur[cc]],-1);
		}
		ll res=0;
		int u=0;
		for(int j=0;j<len[q[i].k];j++){
			u=nxt[u][s[q[i].k][j]-'a'];
			res+=query(pos[u]);
		}
		if(q[i].flag) ans[q[i].id]+=res;
		else ans[q[i].id]-=res;
	}
}
ll val[maxn];
void dfs2(int u){
	for(int i=0;i<(int)ch[u].size();i++){
		int v=ch[u][i];
		dfs2(v);
		val[u]+=val[v];
	}
}
void solve2(int x){
	sort(q2[x].begin(),q2[x].end());
	int u=0;
	for(int i=0;i<len[x];i++){
		u=nxt[u][s[x][i]-'a'];
		val[u]++;
	}
	dfs2(0);
	int cc=0;
	ll res=0;
	for(int i=0;i<(int)q2[x].size();i++){
		while(cc<q2[x][i].x) res+=val[cur[++cc]];
		if(q2[x][i].flag) ans[q2[x][i].id]+=res;
		else ans[q2[x][i].id]-=res;
	}
	memset(val,0,sizeof(val));
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",res);
		len[i]=strlen(res);
		s[i]=new char[len[i]+1];
		strcpy(s[i],res);
		cur[i]=insert(s[i],len[i]);
	}
	build();
	f.push_back(-1);
	dfs(0);
	for(int i=0;i<m;i++){
		int l,r,k;
		l=readint();
		r=readint();
		k=readint();
		if(len[k]>300){
			q2[k].push_back(qry(r,k,i,1));
			q2[k].push_back(qry(l-1,k,i,0));
		}
		else{
			q.push_back(qry(r,k,i,1));
			q.push_back(qry(l-1,k,i,0));
		}
	}
	solve1();
	for(int i=1;i<=n;i++) if(len[i]>300) solve2(i);
	for(int i=0;i<m;i++) printf("%lld\n",ans[i]);
	return 0;
}