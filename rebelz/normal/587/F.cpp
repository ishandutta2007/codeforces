#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,k,id;
	bool operator<(const node c)const{return k<c.k;}
}a[100005];

int n,Q,ncnt,tcnt,blo1,blo2;
vector<int> vec[100005],ed[100005],adj[100005],qry[100005];
int ch[100005][26],fail[100005],q[100005],siz[100005],len[100005];
ll sum[100005],g[100005],sg[100005],ans[100005];
char s[100005];

void insert(char *s,int id){
	int l=strlen(s+1),p=0;
	for(int i=1;i<=l;i++){
		if(!ch[p][s[i]-'a']) ch[p][s[i]-'a']=++ncnt;
		p=ch[p][s[i]-'a'];
		vec[p].push_back(id);
	}
	ed[p].push_back(id);
}

void getfail(){
	int front=0,rear=0;
	q[rear++]=0;
	while(front<rear){
		int t=q[front++];
		for(int i=0;i<26;i++){
			if(ch[t][i]){
				q[rear++]=ch[t][i];
				fail[ch[t][i]]=t?ch[fail[t]][i]:0;
			}
			else ch[t][i]=t?ch[fail[t]][i]:0;
		}
	}
	for(int i=1;i<=ncnt;i++) adj[fail[i]].push_back(i);
}

void dfs1(int u,int id){
	for(auto x:vec[u]) if(x==id) siz[u]++;
	for(auto v:adj[u]) dfs1(v,id),siz[u]+=siz[v];
	for(auto x:ed[u]) sum[x]+=siz[u];
}

void add(int x,int c){
	int bl=(x-1)/blo2+1;
	while((x-1)/blo2+1==bl) g[x++]+=c;
	while(bl<=(n-1)/blo2+1) sg[bl++]+=c;
}

ll ask(int x){return g[x]+sg[(x-1)/blo2];}

void dfs2(int u){
	for(auto x:ed[u]) add(x,1);
	for(auto x:vec[u]) for(auto y:qry[x]) ans[a[y].id]+=ask(a[y].r)-ask(a[y].l-1);
	for(auto v:adj[u]) dfs2(v);
	for(auto x:ed[u]) add(x,-1);
}

int main(){
	n=readint(); Q=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert(s,i);
		len[i]=strlen(s+1);
	}
	blo1=sqrt(ncnt),blo2=sqrt(n);
	getfail();
	for(int i=1;i<=Q;i++) a[i].l=readint(),a[i].r=readint(),a[i].k=readint(),a[i].id=i;
	sort(a+1,a+Q+1);
	for(int i=1;i<=Q;i++){
		if(a[i].k!=a[i-1].k&&len[a[i].k]>blo1){
			memset(sum,0,sizeof(sum));
			memset(siz,0,sizeof(siz));
			dfs1(0,a[i].k);
			for(int j=1;j<=n;j++) sum[j]+=sum[j-1];
		}
		if(len[a[i].k]>blo1) ans[a[i].id]=sum[a[i].r]-sum[a[i].l-1];
		else qry[a[i].k].push_back(i);
	}
	dfs2(0);
	for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
}