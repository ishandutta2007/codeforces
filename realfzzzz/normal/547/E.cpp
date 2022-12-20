//***txdy!
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
const int maxn=2e5+5,maxq=5e5+5,sigma=26;
int n,q;
char *s[maxn],res[maxn];
int l[maxn];
int sz=1,nxt[maxn][sigma],fail[maxn];
vector<int> ch[maxn];
int insert(char *s,int l){
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
	for(int i=0;i<sigma;i++) if(nxt[0][i]){
		fail[nxt[0][i]]=0;
		q.push(nxt[0][i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<sigma;i++){
			if(nxt[u][i]){
				fail[nxt[u][i]]=nxt[fail[u]][i];
				q.push(nxt[u][i]);
			}
			else nxt[u][i]=nxt[fail[u]][i];
		}
	}
}
typedef unsigned uint;
int cnt=0,size[maxn],dfn[maxn];
void dfs(int u){
	size[u]=1;
	dfn[u]=++cnt;
	for(uint i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dfs(v);
		size[u]+=size[v];
	}
}
int pos[maxn];
int k[maxq];
vector<int> q2[maxn];
int c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,int k){
	while(x<=sz){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
int ans[maxq];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    q=readint();
    for(int i=1;i<=n;i++){
    	scanf("%s",res);
    	l[i]=strlen(res);
    	s[i]=new char[l[i]+1];
    	strcpy(s[i],res);
    	pos[i]=insert(s[i],l[i]);
	}
	build();
	for(int i=1;i<=q;i++){
		int l,r;
		l=readint();
		r=readint();
		k[i]=readint();
		if(l>1) q2[l-1].push_back(-i);
		q2[r].push_back(i);
	}
	for(int i=1;i<sz;i++) ch[fail[i]].push_back(i);
	dfs(0);
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=0;j<l[i];j++){
			u=nxt[u][s[i][j]-'a'];
			modify(dfn[u],1);
		}
		for(uint j=0;j<q2[i].size();j++){
			int qq=q2[i][j];
			if(qq>0) ans[qq]+=query(dfn[pos[k[qq]]]+size[pos[k[qq]]]-1)-query(dfn[pos[k[qq]]]-1);
			else ans[-qq]-=query(dfn[pos[k[-qq]]]+size[pos[k[-qq]]]-1)-query(dfn[pos[k[-qq]]]-1);
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}