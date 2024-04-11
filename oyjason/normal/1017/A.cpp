#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200000
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
struct sc{int sum,id;}p[M];
bool cmp(sc i,sc j){return i.sum==j.sum?i.id<j.id:i.sum>j.sum;}
int n,m;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		p[i].id=i,p[i].sum=0;
		for(int j=1;j<=4;j++) m=read(),p[i].sum+=m;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) if(p[i].id==1) m=i;
	printf("%d\n",m);
	return 0;
}