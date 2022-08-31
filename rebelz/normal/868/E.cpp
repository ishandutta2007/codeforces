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

int n,m,tot,s;
int v[105],c[105],nxt[105],h[55],d[55][55][55][2],tmp[55],f[55];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa,int x,int y,int cp){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u;
		dfs1(v[p],u,x,y,c[p]);
	}
	if(!nxt[h[u]]&&u!=1&&y>0){
		chkmin(d[u][x][y][1],d[u][x][0][0]+cp);
	}
	if(!nxt[h[u]]&&u!=1) return;
	if(u==1) return;
	int l=0,r=200000,res=0;
	while(l<=r){
		int mid=(l+r)/2,fl=1,sL=0,sR=0;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			int L=1<<30,R=0;
			for(int i=0;i<=y;i++) if(d[v[p]][x+y-i][i][1]>=mid) chkmin(L,i),chkmax(R,i);
			if(L>R){
				fl=0;
				break;
			}
			sL+=L,sR+=R;
		}
		if(fl&&sL<=y&&sR>=y) res=mid,l=mid+1;
		else r=mid-1;
	}
	d[u][x][y][1]=res+cp;
}

void dfs2(int u,int fa,int x,int y){
	if(u==1&&!nxt[h[u]]){
		for(int p=h[u];p;p=nxt[p]){
			chkmin(d[v[p]][x][y][0],d[v[p]][0][y][1]+c[p]);
			dfs2(v[p],u,x,y);
		}
	}
	else{
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			int l=0,r=200000,res=0;
			while(l<=r){
				int mid=(l+r)/2,fl=1,sL=0,sR=0;
				for(int p2=h[u];p2;p2=nxt[p2]){
					if(p==p2) continue;
					int L=1<<30,R=0;
					for(int i=0;i<=x;i++){
						if(v[p2]==fa){
							if(d[u][i][x+y-i][0]>=mid) chkmin(L,i),chkmax(R,i);
						}
						else{
							if(d[v[p2]][x+y-i][i][1]>=mid) chkmin(L,i),chkmax(R,i);
						}
					}
					if(L>R){
						fl=0;
						break;
					}
					sL+=L,sR+=R;
				}
				if(fl&&sL<=x&&x<=sR) res=mid,l=mid+1;
				else r=mid-1;
			}
			d[v[p]][x][y][0]=res+c[p];
			dfs2(v[p],u,x,y);
		}
	}
}

void dfs3(int u,int fa){
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa) dfs3(v[p],u),tmp[u]+=tmp[v[p]];
}

int main(){
	n=readint();
	int x,y,z;
	for(int i=1;i<n;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	s=readint(); m=readint();
	for(int i=1;i<=m;i++) tmp[readint()]++;
	memset(d,0x3f,sizeof(d));
	for(int i=2;i<=n;i++) for(int j=0;j<=1;j++) d[i][0][0][j]=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j>=0;j--) dfs1(1,-1,j,i-j,-1);
		for(int j=0;j<=i;j++) dfs2(1,-1,j,i-j);
	}
	dfs3(1,-1);
	int ans=1<<30;
	for(int p=h[s];p;p=nxt[p]){
		if(v[p]==f[s]) chkmin(ans,d[s][m-tmp[s]][tmp[s]][0]);
		else chkmin(ans,d[v[p]][m-tmp[v[p]]][tmp[v[p]]][1]);
	}
	printf("%d\n",ans);
	return 0;
}