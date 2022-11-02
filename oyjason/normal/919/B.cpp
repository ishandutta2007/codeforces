#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 20
using namespace std;
LL read(){
	LL num=0,oe=1;char cw=getchar();
	while(!isdigit(cw)) oe=cw=='-'?-1:1,cw=getchar();
	while(isdigit(cw)) num=num*10+cw-'0',cw=getchar();
	return num*oe;
}
LL n,cnt,t[M];
LL sum(LL x){return x<10?x%10:(x%10)+sum(x/10);}
void pt(LL m){
	for(LL i=0;i<m;i++) printf("%I64d",t[i]);
	exit(0);
}
void calc(LL len,LL now,LL tot){
	if(now==len){
		n--;
		if(n==0) pt(len);
		return;
	}
	if(now+1==len){
		if(tot==10) return;
		t[now]=tot,calc(len,now+1,0ll);
		return;
	}
	for(LL i=now==0ll?1ll:0ll;i<=9&&i<=tot;i++){
		t[now]=i,calc(len,now+1,tot-i);
	}
}
int main(){
	n=read();
	for(LL i=2;i<=20;i++){
		calc(i,0,10);
	}
	return 0;
}