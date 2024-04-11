#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int n,m,a[222][222],row[222],col[222];
bitset<222> rb[222],bt[222][222];
bool dfs(int x){
	bool flag=true;
	FOR(y,1,n){
		if(x==y) continue;
		int v=row[x]^bt[x][y][1];
		if(row[y]==-1){
			row[y]=v;
			flag&=dfs(y);
		}
		else if(row[y]!=v) return false;
	}
	return flag;
}
bool check(int x,int y){
	FOR(i,1,n) FOR(j,1,n){
		if(i==j) continue;
		int c=bt[i][j].count();
		if(c!=0 && c!=m) return false;
	}
	MEM(row,-1);
	row[1]=0;
	return dfs(1);
}
void output(){
	puts("YES");
	FOR(i,1,n) printf("%d",row[i]);
	puts("");
	FOR(i,1,m) printf("%d",row[1]^rb[1][i]);
}
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,m) a[i][j]=read(),rb[i][j]=a[i][j]^1;
	FOR(i,1,n) FOR(j,1,n) if(i!=j) bt[i][j]=rb[i]^rb[j];
	if(check(0,0)) return output(),0;
	FOR(i,1,n) FOR(j,1,m){
		rb[i][j]=rb[i][j]^1;
		FOR(k,1,n) if(i!=k) bt[i][k][j]=bt[i][k][j]^1,bt[k][i][j]=bt[k][i][j]^1;
		if(check(i,j)) return output(),0;
	}
	puts("NO");
}