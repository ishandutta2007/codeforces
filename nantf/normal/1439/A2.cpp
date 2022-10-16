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
int n,m,ans[maxn*maxn*3][6],al,b[maxn][maxn],a[maxn][maxn];
char s[maxn][maxn];
inline void add(int X1,int Y1,int X2,int Y2,int X3,int Y3){
	ans[++al][0]=X1;
	ans[al][1]=Y1;
	ans[al][2]=X2;
	ans[al][3]=Y2;
	ans[al][4]=X3;
	ans[al][5]=Y3;
}
void work(int X,int Y){
	bool f0=false,f1=false,f2=false,f3=false,tot=false;
	if(a[X][Y]) f0^=1,tot^=1;
	if(a[X][Y+1]) f1^=1,tot^=1;
	if(a[X+1][Y]) f2^=1,tot^=1;
	if(a[X+1][Y+1]) f3^=1,tot^=1;
	if(f0^tot) add(X+1,Y,X,Y+1,X+1,Y+1);
	if(f1^tot) add(X,Y,X+1,Y,X+1,Y+1);
	if(f2^tot) add(X,Y,X,Y+1,X+1,Y+1);
	if(f3^tot) add(X,Y,X,Y+1,X+1,Y);
}
void work1(){
	FOR(i,1,n-1) FOR(j,1,m-1) if(i%2==1 && j%2==1) work(i,j);
}
void clear(){
	al=0;
	FOR(i,1,n) FOR(j,1,m) b[i][j]=0;
}
void solve(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",s[i]+1);
	FOR(i,1,n) FOR(j,1,m) a[i][j]=s[i][j]-'0';
	if(n%2==1){
		if(m%2==1){
			if(a[n][m]) a[n-1][m]^=1,a[n][m-1]^=1;
			FOR(i,1,m-1) if(i%2==1 && (a[n][i] || a[n][i+1])) a[n-1][i]^=1,b[n-1][i]=1;
			FOR(i,1,n-1) if(i%2==1 && (a[i][m] || a[i+1][m])) a[i][m-1]^=1,b[i][m-1]=1;
			work1();
			FOR(i,1,m-1) a[n-1][i]=b[n-1][i];
			FOR(i,1,n-1) a[i][m-1]=b[i][m-1];
			FOR(i,1,m-1) if(i%2==1) work(n-1,i);
			FOR(i,1,n-1) if(i%2==1) work(i,m-1);
			if(a[n][m]) add(n-1,m,n,m-1,n,m);
		}
		else{
			FOR(i,1,m) if(i%2==1 && (a[n][i] || a[n][i+1])) a[n-1][i]^=1,b[n-1][i]=1;
			work1();
			FOR(i,1,m) a[n-1][i]=b[n-1][i];
			FOR(i,1,m) if(i%2==1) work(n-1,i);
		}
	}
	else{
		if(m%2==1){
			FOR(i,1,n) if(i%2==1 && (a[i][m] || a[i+1][m])) a[i][m-1]^=1,b[i][m-1]=1;
			work1();
			FOR(i,1,n) a[i][m-1]=b[i][m-1];
			FOR(i,1,n) if(i%2==1) work(i,m-1);
		}
		else{
			work1();
		}
	}
	printf("%d\n",al);
	FOR(i,1,al){
		FOR(j,0,5) printf("%d ",ans[i][j]);
		puts("");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}