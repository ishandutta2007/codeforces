#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 500
#define MK 500

using std::min;

const int INF = 0x3f3f3f3f;

int n,l,k;
int a[MN+5],d[MN+5];
int f[2][MN+5][MK+5]; //[limit][removed]

void cmin(int& a,int b){
	a = min(a,b);
}

int main(){
	scanf("%d%d%d",&n,&l,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	d[n] = l;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0] = 0;
	for(int i=1;i<=n;i++){
		int S = i&1;
		int T = S^1;
		memset(f[S],0x3f,sizeof(f[S]));
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				cmin(f[S][j][k+1],f[T][j][k]+a[j]*(d[i]-d[i-1]));
				cmin(f[S][i][k],f[T][j][k]+a[j]*(d[i]-d[i-1]));
			}
		}
	}
	int ans = INF;
	for(int j=0;j<=n;j++){
		for(int k=0;k<=::k;k++){
			cmin(ans,f[n&1][j][k]);
		}
	}
	printf("%d\n",ans);
}