#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int n,m,block,cnt;
int st[200005],en[200005],bl[200005],a[200005],nxt[200005],num[200005],last[200005];

int readint(){
	int x=0; char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

void init(){
	block=sqrt(n);
	for(int i=1;i<=n;i+=block)
		st[++cnt]=i,en[cnt]=i+block-1;
	en[cnt]=n;
	for(int i=1;i<=cnt;i++)
		for(int j=st[i];j<=en[i];j++)
			bl[j]=i;
	for(int i=n;i>=1;i--){
		if(bl[i]!=bl[i+a[i]])
			nxt[i]=i+a[i],num[i]=1,last[i]=i;
		else
			nxt[i]=nxt[i+a[i]],num[i]=num[i+a[i]]+1,last[i]=last[i+a[i]];
	}
}

void change(int x,int p){
	a[x]=p;
	for(int i=en[bl[x]];i>=st[bl[x]];i--){
		if(bl[i]!=bl[i+a[i]])
			nxt[i]=i+a[i],num[i]=1,last[i]=i;
		else
			nxt[i]=nxt[i+a[i]],num[i]=num[i+a[i]]+1,last[i]=last[i+a[i]];
	}
}

void query(int x){
	int ans1=0,ans2=0;
	for(;x<=n;x=nxt[x])
		ans1+=num[x],ans2=last[x];
	printf("%d %d\n",ans2,ans1);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	init();
	int opt,x,y;
	for(int i=1;i<=m;i++){
		opt=readint(); x=readint();
		if(opt==0){
			y=readint();
			change(x,y);
		}
		else
			query(x);
	}
	return 0;
}