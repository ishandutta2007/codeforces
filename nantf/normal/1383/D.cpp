#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=255,mod=998244353;
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
int n,m,a[maxn][maxn],b[maxn][maxn],h=1,r,x,y;
PII q[maxn*maxn];
bool row[maxn*maxn],col[maxn*maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read();
	FOR(i,1,n){
		int id=0;
		FOR(j,1,m) if(a[i][j]>a[i][id]) id=j;
		row[a[i][id]]=true;
	}
	FOR(j,1,m){
		int id=0;
		FOR(i,1,n) if(a[i][j]>a[id][j]) id=i;
		col[a[id][j]]=true;
	}
	ROF(v,n*m,1){
		if(row[v] && col[v]){
			x++;y++;
			ROF(i,x-1,1) q[++r]=MP(i,y);
			ROF(j,y-1,1) q[++r]=MP(x,j);
			b[x][y]=v;
		}
		else if(row[v]){
			x++;
			ROF(j,y-1,1) q[++r]=MP(x,j);
			b[x][y]=v;
		}
		else if(col[v]){
			y++;
			ROF(i,x-1,1) q[++r]=MP(i,y);
			b[x][y]=v;
		}
		else{
			PII p=q[h++];
			b[p.first][p.second]=v;
		}
	}
	FOR(i,1,n){
		FOR(j,1,m) printf("%d ",b[i][j]);
		puts("");
	}
}