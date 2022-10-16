#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500050;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k=500000,mx[maxn],to[maxn][20];
int main(){
	n=read();m=read();
	FOR(i,0,k) mx[i]=i;
	FOR(i,1,n){
		int l=read(),r=read();
		mx[l]=max(mx[l],r);
	}
	FOR(i,1,k) mx[i]=max(mx[i-1],mx[i]);
	FOR(i,0,k) to[i][0]=mx[i];
	FOR(j,1,19) FOR(i,0,k) to[i][j]=to[to[i][j-1]][j-1];
	while(m--){
		int x=read(),y=read(),cnt=0;
		ROF(i,19,0) if(to[x][i]<y) cnt+=1<<i,x=to[x][i];
		if(to[x][0]<y) puts("-1");
		else printf("%d\n",cnt+1);
	}
}
// orz PB AC G