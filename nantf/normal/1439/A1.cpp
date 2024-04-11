#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
int n,m,ans[maxn*maxn*3][6],al;
char a[maxn][maxn];
inline void add(int X1,int Y1,int X2,int Y2,int X3,int Y3){
	ans[++al][0]=X1;
	ans[al][1]=Y1;
	ans[al][2]=X2;
	ans[al][3]=Y2;
	ans[al][4]=X3;
	ans[al][5]=Y3;
}
void solve(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",a[i]+1);
	FOR(i,1,n) FOR(j,1,m) if(a[i][j]=='1'){
		if(i==1 && j==1){
			add(i,j,i+1,j,i,j+1);
			add(i,j,i+1,j,i+1,j+1);
			add(i,j,i,j+1,i+1,j+1);
		}
		else if(i==1){
			add(i,j,i+1,j,i,j-1);
			add(i,j,i+1,j,i+1,j-1);
			add(i,j,i,j-1,i+1,j-1);
		}
		else if(j==1){
			add(i,j,i-1,j,i,j+1);
			add(i,j,i-1,j,i-1,j+1);
			add(i,j,i,j+1,i-1,j+1);
		}
		else{
			add(i,j,i-1,j,i,j-1);
			add(i,j,i-1,j,i-1,j-1);
			add(i,j,i,j-1,i-1,j-1);
		}
	}
	printf("%d\n",al);
	FOR(i,1,al){
		FOR(j,0,5) printf("%d ",ans[i][j]);
		puts("");
	}
	al=0;
}
int main(){
	int T=read();
	while(T--) solve();
}