#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,ct0,ct1,cnt[2],ans;
char ch[M],t[M];
int main(){
	n=read(),scanf("%s",ch+1),scanf("%s",t+1);
	for(int i=1;i<=n;i++){
		cnt[ch[i]-'0']++;
		if(ch[i]=='0'&&t[i]=='0') ct0++;
		if(ch[i]=='1'&&t[i]=='0') ct1++;
	}
	ans=cnt[0]*ct1+cnt[1]*ct0-ct1*ct0;
	printf("%I64d\n",ans);
	return 0;
}