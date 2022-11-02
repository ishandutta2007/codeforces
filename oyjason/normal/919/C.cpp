#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 2020
using namespace std;
LL read(){
	LL num=0,oe=1;char cw=getchar();
	while(!isdigit(cw)) oe=cw=='-'?-1:1,cw=getchar();
	while(isdigit(cw)) num=num*10+cw-'0',cw=getchar();
	return num*oe;
}
LL n,m,k,ans,last;
char ch[M][M];
int main(){
	n=read(),m=read(),k=read();
	for(LL i=0;i<n;i++){
		scanf("%s",ch[i]),last=-1ll;
		for(LL j=0;j<=m+1;j++){
			if(ch[i][j]=='.'&&j<=m) continue;
			if(j-last-1>=k) ans+=j-last-k;
			last=j;
		}
	}
	for(LL i=0;i<m;i++){
		last=-1ll;
		for(LL j=0;j<=n+1;j++){
			if(ch[j][i]=='.'&&j<=n) continue;
			if(j-last-1>=k) ans+=j-last-k;
			last=j;
		}
	}
	if(k==1) ans/=2;
	printf("%I64d\n",ans);
	return 0;
}