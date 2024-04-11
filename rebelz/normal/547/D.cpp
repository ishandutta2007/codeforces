#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt,tot,nx,ny;
int v[1000005],id[1000005],nxt[1000005],rev[1000005],h[400005],x[200005],y[200005],px[200005],py[200005],col[200005],vc[400005],du[400005];
bool vis[400005],used[1000005];

void addedge(int x,int y,int z){
	v[++tot]=y; id[tot]=z; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; id[tot]=z; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int &p=h[u];p;p=nxt[p]){
		if(v[p]==fa||used[p]||used[rev[p]]) continue;
		used[p]=used[rev[p]]=true;
		int tmp=id[p];
		dfs(v[p],u);
		vc[++cnt]=tmp;
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint(),px[++nx]=x[i],py[++ny]=y[i];
	sort(px+1,px+nx+1); nx=unique(px+1,px+nx+1)-px-1;
	sort(py+1,py+ny+1); ny=unique(py+1,py+ny+1)-py-1;
	for(int i=1;i<=n;i++) x[i]=lower_bound(px+1,px+nx+1,x[i])-px,y[i]=lower_bound(py+1,py+ny+1,y[i])-py;
	for(int i=1;i<=n;i++) addedge(x[i],y[i]+nx,i),du[x[i]]++,du[y[i]+nx]++;
	for(int i=1;i<=nx;i++) if(du[i]&1) addedge(i,0,0);
	for(int i=1;i<=ny;i++) if(du[i+nx]&1) addedge(0,i+nx,0);
	for(int i=0;i<=nx+ny;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(i,-1);
		}
	}
	for(int i=1;i<=cnt;i++) col[vc[i]]=col[vc[i-1]]^1;
	for(int i=1;i<=n;i++) printf("%c",col[i]==0?'r':'b');
	printf("\n");
	return 0;
}