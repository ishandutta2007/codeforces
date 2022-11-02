#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
#define INF 1000000020
#define M 100010
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,a[M],F[M][9];
bool vis[M][3]; 
char ch[M];

int main(){
	n=read(),memset(F,0x3f,sizeof(F)),F[0][0]=0;
	for(int i=1;i<=n;i++){
		a[i]=read(),scanf("%s",ch+1);
		int len=strlen(ch+1),tmp=0;
		for(int j=1;j<=len;j++)	tmp=tmp|(1<<(ch[j]-'A'));
		for(int j=0;j<8;j++) F[i][j]=F[i-1][j];
		for(int j=0;j<8;j++) F[i][j|tmp]=min(F[i-1][j]+a[i],F[i][j|tmp]);
	}
	if(F[n][7]<INF) printf("%d\n",F[n][7]);
	else puts("-1");return 0;
}