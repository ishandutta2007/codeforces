#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
#define M 
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,T,t1,t2,x1,x2,y1,y2,ans;
int ABS(int x,int y){return x>y?x-y:y-x;}
int main(){
	n=read(),T=read(),t1=read(),t2=read(),T=read();
	while(T--){
		x1=read(),y1=read(),x2=read(),y2=read();
		ans=ABS(x1,x2)+ABS(y1,y2);
		if(x1!=x2){
			if(y1<t1&&y2<t1) m=max(y1,y2),ans+=2*(t1-m);
			if(y1>t2&&y2>t2) m=min(y1,y2),ans+=2*(m-t2);
		}
		printf("%d\n",ans);
	}
	return 0;
}