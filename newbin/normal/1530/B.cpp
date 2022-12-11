#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<string.h>
using namespace std;
#ifdef LOCAL
FILE*FP=freopen("text.in","r",stdin);
//FILE*fp=freopen("text.out","w",stdout);
#endif
#define N 23
int t,h,w,m[N][N];
int fh[8]={-1,-1,-1,0,0,1,1,1};
int fw[8]={-1,0,1,-1,1,-1,0,1};
bool jd(int i,int j){
	for(int k=0;k<8;k++){
		if(m[i+fh[k]][j+fw[k]])return false;
	}
	return true;
}
signed main(){
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		memset(m,0,sizeof(m));
		m[1][1]=1;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if((i==1||i==h||j==1||j==w)&&jd(i,j)){
					m[i][j]=1;
				}
			}
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				printf("%d",m[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}