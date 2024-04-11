#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,mod=998244353,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,Q,mp[maxn][maxn],h=1,r,q[maxn*maxn][2];
ll d[maxn][maxn]; 
char s[maxn];
bool vis[maxn][maxn];
int main(){
	n=read();m=read();Q=read();
	FOR(i,1,n){
		scanf("%s",s+1);
		FOR(j,1,m) mp[i][j]=s[j]-'0';
	}
	FOR(i,1,n) FOR(j,1,m) d[i][j]=1e18+1;
	FOR(i,1,n) FOR(j,1,m){
		bool flag=false;
		FOR(k,0,3){
			int x=i+dir[k][0],y=j+dir[k][1];
			if(x<1 || x>n || y<1 || y>m) continue;
			if(mp[i][j]==mp[x][y]) flag=true;
		}
		if(flag) q[++r][0]=i,q[r][1]=j,vis[i][j]=true,d[i][j]=0;
	}
	while(h<=r){
		int x=q[h][0],y=q[h][1];h++;
		FOR(k,0,3){
			int tx=x+dir[k][0],ty=y+dir[k][1];
			if(tx<1 || tx>n || ty<1 || ty>m) continue;
			if(mp[tx][ty]==mp[x][y] || vis[tx][ty]) continue;
			vis[tx][ty]=true;
			d[tx][ty]=d[x][y]+1;
			q[++r][0]=tx;q[r][1]=ty;
		}
	}
	while(Q--){
		int x=read(),y=read();
		ll t=read();
		if(t<=d[x][y]) printf("%d\n",mp[x][y]);
		else printf("%lld\n",((t-d[x][y])%2)^mp[x][y]);
	}
}