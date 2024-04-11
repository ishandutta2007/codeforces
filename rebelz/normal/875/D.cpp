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

int n;
int pre[31][200005],nxt[31][200005];
bool vis[30][200005];
pii a[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
	for(int i=0;i<30;i++){
		for(int j=1;j<=n;j++) if((a[j].fi>>i)&1) vis[i][j]=1;
		for(int j=1;j<=n;j++){
			pre[i][j]=pre[i][j-1];
			if(vis[i][j]) pre[i][j]=j;
		}
		nxt[i][n+1]=n+1;
		for(int j=n;j>=1;j--){
			nxt[i][j]=nxt[i][j+1];
			if(vis[i][j]) nxt[i][j]=j;
		}
	}
	sort(a+1,a+n+1);
	nxt[30][0]=1;
	for(int j=1;j<=n;j++) pre[30][j]=j-1,nxt[30][j]=j+1;
	pre[30][n+1]=n;
	ll ans=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++){
		int x=a[i].se,lf=1,rg=n;
		chkmin(rg,nxt[30][x]-1);
		chkmax(lf,pre[30][x]+1);
		int pr=pre[30][x],nx=nxt[30][x];
		pre[30][nx]=pr,nxt[30][pr]=nx;
		for(int j=0;j<30;j++){
			if(!((a[i].fi>>j)&1)){
				chkmin(rg,nxt[j][x]-1);
				chkmax(lf,pre[j][x]+1);
			}
		}
		ans-=1ll*(x-lf+1)*(rg-x+1);
	}
	printf("%lld\n",ans);
	return 0;
}