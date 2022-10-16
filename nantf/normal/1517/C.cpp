#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,p[maxn],ans[maxn][maxn];
void dfs(int x,int y,int v,int &res){
	if(x<1 || x>n || y<1 || y>n || x<y || !res || ans[x][y]) return;
	res--;
	ans[x][y]=v;
	dfs(x,y-1,v,res);
	dfs(x+1,y,v,res);
}
int main(){
	n=read();
	FOR(i,1,n){
		int v=read();
		dfs(i,i,v,v);
/*	FOR(i,1,n){
		FOR(j,1,i) printf("%d ",ans[i][j]);
		puts("");
	}*/
	}
	FOR(i,1,n){
		FOR(j,1,i) printf("%d ",ans[i][j]);
		puts("");
	}
}
/*
5
5 1 4 3 2
*/