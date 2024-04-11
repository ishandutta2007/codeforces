#include<bits/stdc++.h>
using namespace std;
int t,h,w,res[22][22];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&h,&w);
		memset(res,0,sizeof(res));
		res[0][0]=1;
		res[0][w-1]=1;
		res[h-1][0]=1;
		res[h-1][w-1]=1;
		for (int i=1;i<w;i++)
			if (res[0][i-1]==0&&res[0][i+1]==0) res[0][i]=1;
		for (int i=1;i<w;i++)
			if (res[h-1][i-1]==0&&res[h-1][i+1]==0) res[h-1][i]=1;
		for (int i=1;i<h;i++)
			if (res[i-1][0]==0&&res[i+1][0]==0) res[i][0]=1;
		for (int i=1;i<h;i++)
			if (res[i-1][w-1]==0&&res[i+1][w-1]==0) res[i][w-1]=1;
		for (int i=0;i<h;i++){
			for (int j=0;j<w;j++) printf("%d",res[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}