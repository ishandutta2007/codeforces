#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 51
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n;
char a[MN][MN];
int b[MN][MN],f[MN][MN][MN][MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%s",a[i]+1);
	F(i,1,n)F(j,1,n)b[i][j]=a[i][j]=='#';
	F(i,1,n)F(j,1,n)f[i][j][i][j]=b[i][j];
	F(x,1,n)F(y,1,n)if(x>1||y>1)F(i,1,n-x+1)F(j,1,n-y+1){
		int k=i+x-1,l=j+y-1;
		f[i][j][k][l]=max(x,y);
		F2(z,i,k)f[i][j][k][l]=min(f[i][j][k][l],f[i][j][z][l]+f[z+1][j][k][l]);
		F2(z,j,l)f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][z]+f[i][z+1][k][l]);
	}
	printf("%d\n",f[1][1][n][n]);
	return 0;
}