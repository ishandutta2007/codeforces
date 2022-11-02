#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,ans;
void ok(LL x){printf("%lld\n",x);exit(0);}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	if(n>m) swap(n,m);
	if(n==1) ok((m-(m%6))+max(0ll,(m%6-3)*2));
	if(n%2==0&&m%2==0){ 
		if(m==2&&n==2) ok(0);
		else ok(n*m);
	}
	if((n+m)&1){
		if(m&1) swap(n,m);
		if(n==3){
			if(m==2) ok(4);
			else ok(n*m);
		}
		if(n==7){
			if(m==2) ok(12);
			else ok(n*m);
		}
		ok(n*m);
	}
	ok(n*m-1);
	return 0;
}