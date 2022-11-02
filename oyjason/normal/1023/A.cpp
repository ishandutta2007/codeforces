#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,t1,t2;
char ch[M],S[M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),scanf("%s%s",ch+1,S+1);
	if(n>m+1){puts("NO");return 0;}
	while(t1<n&&ch[t1+1]==S[t1+1]&&t1<m) t1++;
	while(t2<n&&t2<m&&ch[n-t2]==S[m-t2]) t2++;
	if((t1+t2==n-1&&ch[t1+1]=='*')||(t1==n&&t2==n&&n==m)) puts("YES");
	else puts("NO");
	return 0;
}