#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,maxk=44,mod=998244353,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,m,K,Q,a[maxn][maxn],dis[maxk][maxn][maxn],q[maxn*maxn][2],h,r;
bool vis[maxk];
vector<PII> v[maxk];
int main(){
	n=read();m=read();K=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read(),v[a[i][j]].push_back(MP(i,j));
	FOR(_,1,K){
		h=1;r=0;
		FOR(i,1,n) FOR(j,1,m) dis[_][i][j]=-1;
		FOR(i,0,(int)v[_].size()-1) dis[_][v[_][i].first][v[_][i].second]=0,q[++r][0]=v[_][i].first,q[r][1]=v[_][i].second;
		FOR(i,1,K) vis[i]=0;
		vis[_]=true;
		while(h<=r){
			int x=q[h][0],y=q[h][1];h++;
			FOR(i,0,3){
				int tx=x+d[i][0],ty=y+d[i][1];
				if(tx<1 || tx>n || ty<1 || ty>m) continue;
				if(~dis[_][tx][ty]) continue;
				dis[_][tx][ty]=dis[_][x][y]+1;
				q[++r][0]=tx,q[r][1]=ty;
			}
			if(!vis[a[x][y]]){
				vis[a[x][y]]=true;
				FOR(i,0,(int)v[a[x][y]].size()-1){
					int tx=v[a[x][y]][i].first,ty=v[a[x][y]][i].second;
					if(~dis[_][tx][ty]) continue;
					dis[_][tx][ty]=dis[_][x][y]+1;
					q[++r][0]=tx,q[r][1]=ty;
				}
			}
		}
	}
	Q=read();
	while(Q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		int ans=abs(x2-x1)+abs(y2-y1);
		FOR(i,1,K) ans=min(ans,dis[i][x1][y1]+dis[i][x2][y2]+1);
		printf("%d\n",ans);
	}
}
// hard or not hard, that is a question