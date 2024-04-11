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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,tot;
ll v[1000005],c[1000005],nxt[1000005],h[500005],d[500005][2];
vector<ll> s[500005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa,int x){
	d[u][0]=0,d[u][1]=x;
	s[u].clear();
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u,c[p]);
		s[u].push_back(d[v[p]][1]-d[v[p]][0]);
		d[u][0]+=d[v[p]][0],d[u][1]+=d[v[p]][0];
	}
	sort(s[u].begin(),s[u].end()); reverse(s[u].begin(),s[u].end());
	for(int i=0;i<k&&i<s[u].size();i++) if(s[u][i]>0) d[u][0]+=s[u][i];
	for(int i=0;i<k-1&&i<s[u].size();i++) if(s[u][i]>0) d[u][1]+=s[u][i];
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		int x,y,z;
		for(int i=1;i<=n-1;i++){
			x=readint(); y=readint(); z=readint();
			addedge(x,y,z);
		}
		dfs(1,-1,0);
		printf("%lld\n",d[1][0]);
	}
	return 0;
}