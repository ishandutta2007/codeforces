#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=5000;
int n,tot,ntot; ll now,ans;
int pt[5005][5005],nxt[5005][5005];
ll prm[5005],tcnt[1000005],dep[1000005],siz[1000005],v[2000005],enxt[2000005],c[2000005],h[1000005];
int lab[5005][5005];
bool fl[5005];

void addedge(int x,int y,int z){
	v[++ntot]=y; c[ntot]=z; enxt[ntot]=h[x]; h[x]=ntot;
	v[++ntot]=x; c[ntot]=z; enxt[ntot]=h[y]; h[y]=ntot;
}

void getprime(){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

void dfs1(int u,int fa){
	siz[u]=tcnt[u];
	for(int p=h[u];p;p=enxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+c[p];
		dfs1(v[p],u);
		now+=c[p]*siz[v[p]];
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa){
	for(int p=h[u];p;p=enxt[p]){
		if(v[p]==fa) continue;
		now-=siz[v[p]]*c[p];
		now+=(siz[u]-siz[v[p]])*c[p];
		chkmin(ans,now);
		int tmp1=siz[u],tmp2=siz[v[p]];
		siz[u]=tmp1-tmp2,siz[v[p]]=tmp1;
		dfs2(v[p],u);
		siz[u]=tmp1,siz[v[p]]=tmp2;
		now-=(siz[u]-siz[v[p]])*c[p];
		now+=siz[v[p]]*c[p];
	}
}

int main(){
	getprime();
	n=readint();
	for(int i=1;i<=n;i++) tcnt[readint()]++;
	for(int i=0;i<=N;i++)
		for(int j=1;j<=tot;j++)
			for(int k=prm[j];k<=N;k*=prm[j])
				pt[i][j]+=i/k;
	memset(nxt,-1,sizeof(nxt));
	nxt[tot+1][0]=N;
	for(int i=tot;i>=1;i--){
		for(int j=0;j<=N;j++){
			if(nxt[i+1][j]<0) continue;
			int st=j;
			for(int k=j+1;k<=nxt[i+1][j];k++) if(pt[k-1][i]!=pt[k][i]) nxt[i][st]=k-1,st=k;
			nxt[i][st]=nxt[i+1][j];
		}
	}
	for(int i=0;i<=N;i++) nxt[0][i]=i,lab[0][i]=i;
	int cnt=N;
	for(int i=1;i<=tot+1;i++) for(int j=0;j<=N;j++) if(nxt[i][j]>=0) lab[i][j]=++cnt;
	for(int i=1;i<=tot+1;i++){
		for(int j=0;j<=N;j++){
			if(!nxt[i][j]) continue;
			for(int k=j;k<=nxt[i][j];k++){
				if(nxt[i-1][k]>=0)
					addedge(lab[i][j],lab[i-1][k],pt[k][i-1]-pt[j][i-1]+(i>1?pt[k][i-2]:0));
			}
		}
	}
	dfs1(0,-1);
	ans=now;
	dfs2(0,-1);
	printf("%lld\n",ans);
	return 0;
}