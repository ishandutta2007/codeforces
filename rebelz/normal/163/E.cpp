#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=1000002;
int n,k,tot,pnum,cnt,rt;
char s[1000005];
bool vis[100005];
int dfn[1000005],v[1000005],nxt[1000005],h[1000005],siz[1000005],pl[100005],ch[1000005][26],q[1000005],fail[1000005];
ll c[1000005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}
int lowbit(int x){return x&(-x);}
void add(int x,int g){for(;x<=N;x+=lowbit(x))c[x]+=g;}
ll ask(int x){ll ret=0;for(;x;x-=lowbit(x))ret+=c[x];return ret;}

int insert(char *s){
	int m=strlen(s+1),p=rt;
	for(int i=1;i<=m;i++){
		if(!ch[p][s[i]-'a']) ch[p][s[i]-'a']=++pnum;
		p=ch[p][s[i]-'a'];
	}
	return p;
}

void getnext(){
	int front=0,rear=0;
	q[rear++]=rt;
	while(front<rear){
		int t=q[front++];
		for(int i=0;i<26;i++){
			if(ch[t][i]){
				fail[ch[t][i]]=!t?0:ch[fail[t]][i];
				addedge(fail[ch[t][i]],ch[t][i]);
				q[rear++]=ch[t][i];
			}
			else ch[t][i]=!t?t:ch[fail[t]][i];
		}
	}
}

void dfs(int u){
	dfn[u]=++cnt,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]) dfs(v[p]),siz[u]+=siz[v[p]];
}

ll getans(char *s){
	ll ans=0,m=strlen(s+1),p=rt;
	for(int i=1;i<=m;i++){
		p=ch[p][s[i]-'a'];
		ans+=ask(dfn[p]);
	}
	return ans;
}

int getnum(char *s){
	int m=strlen(s+1),res=0;
	for(int i=1;i<=m;i++) res=res*10+s[i]-'0';
	return res;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=k;i++){
		scanf("%s",s+1);
		pl[i]=insert(s);
	}
	getnext();
	dfs(rt);
	int num;
	for(int i=1;i<=k;i++) vis[i]=true,add(dfn[pl[i]],1),add(dfn[pl[i]]+siz[pl[i]],-1);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='?') printf("%lld\n",getans(s));
		else num=getnum(s);
		if(s[0]=='+'&&!vis[num]) add(dfn[pl[num]],1),add(dfn[pl[num]]+siz[pl[num]],-1),vis[num]=true;
		else if(s[0]=='-'&&vis[num]) add(dfn[pl[num]],-1),add(dfn[pl[num]]+siz[pl[num]],1),vis[num]=false;
	}
	return 0;
}