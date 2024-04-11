#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN][MN];
inline int ask(int sx,int sy,int tx,int ty){
	printf("? %d %d %d %d\n",sx,sy,tx,ty),fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
inline void print(int x){
	F(i,1,n)F(j,1,n)if((i+j)&1)a[i][j]^=x;
	puts("!");
	F(i,1,n){F(j,1,n)printf("%d",a[i][j]);puts("");}
}
int main(){
	scanf("%d",&n);
	F(i,1,n)F(j,1,n)a[i][j]=2;
	a[1][1]=1,a[n][n]=0;
	F(i,1,n)F(j,1,n){
		if(i==1&&j==1)continue;
		if(i==n&&j==n)continue;
		if((i+j)&1)continue;
		if(i==1) a[i][j]=a[i][j-2]^(ask(i,j-2,i,j)^1);
		if(j==1) a[i][j]=a[i-2][j]^(ask(i-2,j,i,j)^1);
		if(i!=1&&j!=1) a[i][j]=a[i-1][j-1]^(ask(i-1,j-1,i,j)^1);
	}
	F(i,1,n){
		if(i==1){
			for(int j=4;j<=n;j+=2)
				a[i][j]=a[i][j-2]^(ask(i,j-2,i,j)^1);
		}
		else if(i&1){
			for(int j=2;j<=n;j+=2)
				a[i][j]=a[i-1][j-1]^(ask(i-1,j-1,i,j)^1);
		}
		else if(~i&1){
			a[i][n]=a[i-1][n-1]^(ask(i-1,n-1,i,n)^1);
			for(int j=n-2;j>=1;j-=2)
				a[i][j]=a[i][j+2]^(ask(i,j,i,j+2)^1);
		}
	}
	F(i,1,n-1)F(j,1,n-2){
		if(a[i+1][j]!=a[i][j+1]||a[i+1][j+1]!=a[i][j+2]||(a[i][j]^a[i][j+1]^a[i][j+2]^a[i+1][j+2])==0){
			int d=ask(i,j,i+1,j+2)^1;
			return print(a[i][j]^a[i+1][j+2]^d),0;
		}
	}
	return 0;
}