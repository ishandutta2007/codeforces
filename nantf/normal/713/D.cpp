#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,mod=998244353;
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
void write(int x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int n,m,q,mp[maxn][maxn],pre[maxn][maxn],val[maxn][maxn],st[11][11][maxn][maxn],logt[maxn];
inline int sum(int x1,int y1,int x2,int y2){
	return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
}
inline int query(int x1,int y1,int x2,int y2){
	int k1=logt[x2-x1+1],k2=logt[y2-y1+1],ans=0;
	ans=max(ans,st[k1][k2][x1][y1]);
	ans=max(ans,st[k1][k2][x2-(1<<k1)+1][y1]);
	ans=max(ans,st[k1][k2][x1][y2-(1<<k2)+1]);
	ans=max(ans,st[k1][k2][x2-(1<<k1)+1][y2-(1<<k2)+1]);
//	printf("query(%d,%d,%d,%d)=%d\n",x1,y1,x2,y2,ans);
	return ans;
}
int main(){
//	freopen("city.in","r",stdin);
//	freopen("city.out","w",stdout);
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) mp[i][j]=read(),pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+mp[i][j];
	FOR(i,1,n) FOR(j,1,m){
		if(!mp[i][j]) continue;
		int l=1,r=min(n-i+1,m-j+1);
		while(l<r){
			int mid=(l+r+1)/2;
			if(sum(i,j,i+mid-1,j+mid-1)==mid*mid) l=mid;
			else r=mid-1;
		}
		val[i][j]=l;
	}
	FOR(i,2,max(n,m)) logt[i]=logt[i>>1]+1;
	FOR(i,1,n) FOR(j,1,m) st[0][0][i][j]=val[i][j];
	FOR(i,0,logt[n]) FOR(j,0,logt[m]){
		if(!i && !j) continue;
		FOR(k,1,n-(1<<i)+1) FOR(l,1,m-(1<<j)+1){
			if(i) st[i][j][k][l]=max(st[i][j][k][l],st[i-1][j][k][l]);
			if(j) st[i][j][k][l]=max(st[i][j][k][l],st[i][j-1][k][l]);
			if(i) st[i][j][k][l]=max(st[i][j][k][l],st[i-1][j][k+(1<<(i-1))][l]);
			if(j) st[i][j][k][l]=max(st[i][j][k][l],st[i][j-1][k][l+(1<<(j-1))]);
		}
	}
	q=read();
	while(q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		int ans=0;
		if(!sum(x1,y1,x2,y2)){
			putchar('0');putchar('\n');
			continue;
		}
		if(sum(x1,y1,x2,y2)==1){
			putchar('1');putchar('\n');
			continue;
		}
		int l=1,r=min(x2-x1+1,y2-y1+1);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query(x1,y1,x2-mid+1,y2-mid+1)>=mid) l=mid;
			else r=mid-1;
		}
		write(l);putchar('\n');
	}
}
/*
3 4
1 1 0 1
0 1 1 0
0 1 1 0
5
1 1 2 3
2 1 3 2
3 2 3 4
1 1 3 4
1 2 3 4
*/