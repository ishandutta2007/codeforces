#include <stdio.h>
#include <algorithm>
const int N =16;
int D[1<<N][N*N];
bool tp[N];int a[N],b[N];
int main(){
	int n;scanf("%d",&n);
	int xx=0,yy=0;
	for(int i=0;i<n;i++){
		char c; 
		scanf(" %c",&c);
		tp[i] = (c=='R');
		scanf("%d %d",a+i,b+i);
		xx+=a[i];
		yy+=b[i];
	}
	int M = n*n;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<M;j++) D[i][j]=-1;
	}
	D[0][0]=0;
	for(int i=0;i<(1<<n);i++){
		int x =0,y=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(tp[j])x++;
				else y++;
			}
		}
		for(int j=0;j<M;j++){
			if(D[i][j]==-1) continue;
			for(int k=0;k<n;k++){
				if(i&(1<<k))continue;
				int xx = j+std::min(x,a[k]);
				int yy = D[i][j]+std::min(y,b[k]);
				D[i+(1<<k)][xx]=std::max(D[i+(1<<k)][xx],yy);
			}
		}
	}
	int ans= 2012345678;
	for(int k=0;k<M;k++){
		if(D[(1<<n)-1][k]>=0){
			ans = std::min(ans, std::max(xx-k,yy-D[(1<<n)-1][k]));
		}
	}
	printf("%d\n",ans+n);
}