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

int n,q,cnt;
int a[1505][1505],sz[1505][1505],ans[1505];
pii bk[1505][1505][11],b[22];
bool vis[2250005];

int dist(pii x,pii y){return max(abs(x.fi-y.fi),abs(x.se-y.se));}

int main(){
	n=readint(); q=readint()+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int pl1=0,pl2=0;
			cnt=0;
			for(int k=1;k<=sz[i-1][j]+sz[i][j-1];k++){
				if(pl1>=sz[i-1][j]) b[++cnt]=bk[i][j-1][pl2++];
				else if(pl2>=sz[i][j-1]) b[++cnt]=bk[i-1][j][pl1++];
				else if(dist(bk[i-1][j][pl1],mp(i,j))<=dist(bk[i][j-1][pl2],mp(i,j))) b[++cnt]=bk[i-1][j][pl1++];
				else b[++cnt]=bk[i][j-1][pl2++];
			}
			b[0]=mp(i,j);
			for(int k=0;k<=sz[i-1][j]+sz[i][j-1];k++){
				if(!vis[a[b[k].fi][b[k].se]]){
					vis[a[b[k].fi][b[k].se]]=1;
					bk[i][j][sz[i][j]++]=b[k];
					if(sz[i][j]==q) break;
				}
			}
			for(int k=0;k<sz[i][j];k++) vis[a[bk[i][j][k].fi][bk[i][j][k].se]]=0;
			int lm=min(i,j)+1;
			if(sz[i][j]==q) chkmin(lm,dist(bk[i][j][q-1],mp(i,j))+1);
			ans[1]++,ans[lm]--;
		}
	}
	for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}