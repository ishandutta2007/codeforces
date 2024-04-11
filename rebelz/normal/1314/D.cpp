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

int n,k,ans=1<<30;
int a[85][85],pl[5],d[6][5];
pii t[85][85][6];
bool vis[85];

int getval(int x,int y){
	for(int i=0;i<5;i++) if(!vis[t[x][y][i].se]) return t[x][y][i].fi;
	assert(0);
}

void dfs(int now){
	for(int i=0;i<=now;i++) vis[pl[i]]=1;
	memset(d,0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1;i<=k/2;i++)
		for(int j=0;j<=now;j++)
			for(int l=0;l<=now;l++)
				chkmin(d[i][j],d[i-1][l]+getval(pl[l],pl[j]));
	chkmin(ans,d[k/2][0]);
	for(int i=0;i<=now;i++) vis[pl[i]]=0;
	if(now==k/2-1) return;
	for(int i=pl[now]+1;i<=n;i++){
		pl[now+1]=i;
		dfs(now+1);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vector<pii> v(0);
			for(int k=1;k<=n;k++) if(i!=k&&j!=k) v.pb(mp(a[i][k]+a[k][j],k));
			sort(v.begin(),v.end());
			for(int k=0;k<5;k++) t[i][j][k]=mp(1<<30,0);
			for(int k=0;k<min(5,(int)v.size());k++) t[i][j][k]=v[k];
		}
	}
	pl[0]=1;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}