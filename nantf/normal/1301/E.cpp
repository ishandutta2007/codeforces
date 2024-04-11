#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555,mod=998244353;
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
int n,m,q,pre[4][maxn][maxn],R[maxn][maxn],G[maxn][maxn],Y[maxn][maxn],B[maxn][maxn],lt[maxn],st[10][10][maxn][maxn];
char s[maxn][maxn];
inline int sum(int x1,int y1,int x2,int y2,int c){
	if(x1>x2 || y1>y2) return 0;
	return pre[c][x2][y2]-pre[c][x1-1][y2]-pre[c][x2][y1-1]+pre[c][x1-1][y1-1];
}
inline int query(int x1,int y1,int x2,int y2){
	int i=lt[x2-x1+1],j=lt[y2-y1+1];
	return max(max(st[i][j][x1][y1],st[i][j][x2-(1<<i)+1][y1]),max(st[i][j][x1][y2-(1<<j)+1],st[i][j][x2-(1<<i)+1][y2-(1<<j)+1]));
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,n) scanf("%s",s[i]+1);
	FOR(i,1,n) FOR(j,1,m){
		FOR(k,0,3) pre[k][i][j]=pre[k][i-1][j]+pre[k][i][j-1]-pre[k][i-1][j-1];
		if(s[i][j]=='R') pre[0][i][j]++;
		if(s[i][j]=='G') pre[1][i][j]++;
		if(s[i][j]=='Y') pre[2][i][j]++;
		if(s[i][j]=='B') pre[3][i][j]++;
	}
	FOR(i,1,n) FOR(j,1,m){
		int l=0,r=min(i,j);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(sum(i-mid+1,j-mid+1,i,j,0)==mid*mid) l=mid;
			else r=mid-1;
		}
		R[i][j]=l;
		l=0;r=min(i,m-j+1);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(sum(i-mid+1,j,i,j+mid-1,1)==mid*mid) l=mid;
			else r=mid-1;
		}
		G[i][j]=l;
		l=0;r=min(n-i+1,j);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(sum(i,j-mid+1,i+mid-1,j,2)==mid*mid) l=mid;
			else r=mid-1;
		}
		Y[i][j]=l;
		l=0;r=min(n-i+1,m-j+1);
		while(l<r){
			int mid=(l+r+1)>>1;
			if(sum(i,j,i+mid-1,j+mid-1,3)==mid*mid) l=mid;
			else r=mid-1;
		}
		B[i][j]=l;
	}
	FOR(i,1,n-1) FOR(j,1,m-1) st[0][0][i][j]=min(min(R[i][j],G[i][j+1]),min(Y[i+1][j],B[i+1][j+1]));
	FOR(i,2,max(n,m)-1) lt[i]=lt[i>>1]+1;
	FOR(i,0,lt[n-1]) FOR(j,0,lt[m-1]) if(i || j){
		FOR(k,1,n-(1<<i)) FOR(l,1,m-(1<<j)){
			if(i) st[i][j][k][l]=max(st[i-1][j][k][l],st[i-1][j][k+(1<<(i-1))][l]);
			if(j) st[i][j][k][l]=max(st[i][j-1][k][l],st[i][j-1][k][l+(1<<(j-1))]);
		}
	}
	while(q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		int l=0,r=min(x2-x1+1,y2-y1+1)/2;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query(x1+mid-1,y1+mid-1,x2-mid,y2-mid)>=mid) l=mid;
			else r=mid-1;
		}
		printf("%d\n",4*l*l);
	}
}
// heavy problem