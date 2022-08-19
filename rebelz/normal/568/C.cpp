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

int n,m,k,tot;
int d[205],v[320005],nxt[320005],h[405],ans[205];
vector<pii> st[205];
char ts[30],s[205];
bool vis[205][2];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

bool getans(int u,int lb){
	st[lb].push_back(mp((u-1)%n+1,d[(u-1)%n+1]));
	d[(u-1)%n+1]=(u-1)/n;
	for(int p=h[u];p;p=nxt[p]){
		if(d[(v[p]-1)%n+1]>=0&&d[(v[p]-1)%n+1]*n+(v[p]-1)%n+1!=v[p]) return false;
		if(d[(v[p]-1)%n+1]>=0) continue;
		getans(v[p],lb);
	}
	return true;
}

bool dfs(int lb,bool pt){
	if(vis[lb][pt]) return false;
	vis[lb][pt]=true;
	if(lb==n+1) return true;
	for(int j=(pt?s[lb]-'a':0);j<k;j++){
		if(d[lb]>=0&&d[lb]!=(ts[j]=='C')) continue;
		st[lb].clear();
		if(!getans(lb+(ts[j]=='C')*n,lb)){
			for(auto x:st[lb]) d[x.fi]=x.se;
			continue;
		}
		ans[lb]=j;
		int fl=dfs(lb+1,pt&(j==s[lb]-'a'));
		if(!fl){
			ans[lb]=-1;
			for(auto x:st[lb]) d[x.fi]=x.se;
		}
		else return true;
	}
	return false;
}

int main(){
	scanf("%s",ts); k=strlen(ts);
	n=readint(); m=readint();
	int x1,x2; char y1[2],y2[2];
	for(int i=1;i<=m;i++){
		x1=readint(); scanf("%s",y1); x2=readint(); scanf("%s",y2);
		addedge(x1+(y1[0]=='C')*n,x2+(y2[0]=='C')*n);
		addedge(x2+((y2[0]=='C')^1)*n,x1+((y1[0]=='C')^1)*n);
	}
	scanf("%s",s+1);
	memset(d,-1,sizeof(d));
	memset(ans,-1,sizeof(ans));
	if(!dfs(1,1)) return printf("-1\n"),0;
	for(int i=1;i<=n;i++) printf("%c",ans[i]+'a');
	printf("\n");
	return 0;
}