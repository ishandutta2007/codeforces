#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL S,A,B=1;
LL len,ans2,ans1;
int main(){
	S=read();A=S;
	while(A) A/=10,len++,B=B*10+1;
	ans1=(len-1)*9,B/=100,S-=B*9;
	while(S) ans2+=S%10,S/=10;
	printf("%lld\n",ans1+ans2);return 0;
}