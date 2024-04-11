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

bool chkmin(pii &x,pii y){return x>y?x=y,1:0;}
bool chkmax(pii &x,pii y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,tot,optx,opty;
pii ans;
int v[400005],nxt[400005],h[200005],tag[200005],col[200005],f[200005],dep[200005],maxa[200005];
pii max1[200005],max2[200005];

pii operator+(const pii x,const pii y){return mp(x.fi+y.fi,x.se+y.se);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	max1[u]=max2[u]=mp(0,u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p],u);
		if(max1[v[p]]+mp(1,0)>max1[u]) max2[u]=max1[u],max1[u]=max1[v[p]]+mp(1,0);
		else if(max1[v[p]]+mp(1,0)>max2[u]) max2[u]=max1[v[p]]+mp(1,0);
	}
	if(chkmax(ans,max1[u]+max2[u])) optx=max1[u].se,opty=max2[u].se;
}

void dfs3(int u,int fa,int dir,int now){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||tag[v[p]]) continue;
		col[v[p]]=(now+k+dir)%k+1;
		dfs3(v[p],u,dir,now+dir);
	}
}

void dfs2(int u,int fa){
	maxa[u]=dep[u];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1;
		dfs2(v[p],u);
		if(!tag[v[p]]) maxa[u]=max(maxa[u],maxa[v[p]]);
	}
	if(tag[u]){
		maxa[u]-=dep[u];
		if(maxa[u]&&maxa[u]+tag[u]>=k&&maxa[u]+ans.fi-tag[u]+2>=k){
			printf("No\n");
			exit(0);
		}
		if(maxa[u]+tag[u]>=k) dfs3(u,-1,1,tag[u]);
		else dfs3(u,-1,-1,tag[u]);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1,-1);
	if(k==2){
		printf("Yes\n");
		for(int i=1;i<=n;i++) printf("%d ",(dep[i]&1)+1);
		printf("\n");
		return 0;
	}
	int lbx=1,lby=ans.fi+1;
	while(optx!=opty){
		if(dep[optx]<dep[opty]) swap(optx,opty),swap(lbx,lby);
		tag[optx]=lbx,col[optx]=lbx%k+1;
		if(lbx>lby) lbx--;
		else lbx++;
		optx=f[optx];
	}
	tag[optx]=lbx,col[optx]=lbx%k+1;
	dep[optx]=1; dfs2(optx,-1);
	printf("Yes\n");
	for(int i=1;i<=n;i++) printf("%d ",col[i]);
	printf("\n");
	return 0;
}