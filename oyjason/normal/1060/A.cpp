#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,p[110],tot;
char s[110];
int main(){
	n=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++) tot=(s[i]-'0'),p[tot]++;
	if(p[8]*11<=n) printf("%d\n",p[8]); else printf("%d\n",n/11);
}