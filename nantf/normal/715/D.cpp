#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010,mod=998244353;
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
ll t;
int bit[maxn],bl,ans[maxn][4],al;
inline void add(int x1,int y1,int x2,int y2){
	ans[++al][0]=x1;
	ans[al][1]=y1;
	ans[al][2]=x2;
	ans[al][3]=y2;
}
int main(){
	scanf("%lld",&t);
	while(t) bit[bl++]=t%3,t/=3;
	FOR(i,1,36){
		add(i,i+4,i,i+5);
		add(i+4,i,i+5,i);
	}
	FOR(i,1,37){
		add(i,i+3,i+1,i+3);
		add(i+3,i,i+3,i+1);
	}
	add(39,40,39,41);
	add(40,40,40,41);
	add(40,40,41,40);
	add(40,39,41,39);
	FOR(i,0,37) if(bit[i]==0){
		add(i+1,i+3,i+1,i+4);
		add(i+3,i+1,i+4,i+1);
	}
	else if(bit[i]==1){
		add(i+1,i+3,i+1,i+4);
	}
	printf("41 41\n%d\n",al);
	FOR(i,1,al) printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
}