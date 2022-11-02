#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,rem,a[110],minn,maxn,pos;
int main(){
	n=read(),rem=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
	
	for(maxn+=rem;rem;a[pos]++,rem--){
		minn=1000000000;
		for(int i=1;i<=n;i++) if(minn>a[i]) minn=a[i],pos=i;
	}
	minn=0;
	for(int i=1;i<=n;i++) minn=max(minn,a[i]);
	printf("%d %d\n",minn,maxn);
}