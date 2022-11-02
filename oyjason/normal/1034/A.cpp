#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
#define MAXN 16000004
#define M 3000020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int fs[MAXN+1],cnt,pri[M],F[MAXN+1],ct,A[300010],ans,sum,gd,DW,n;
bool vis[MAXN+1];
int main(){
	n=read(),ans=n+1;
	for(int i=1;i<=n;i++){
		A[i]=read();
		if(i!=1) gd=gcd(gd,A[i]); else gd=A[i];
		if(i!=1&&A[i]!=1) DW=gcd(DW,A[i]); else if(A[i]!=1) DW=A[i];
	}
	for(int i=1;i<=n;i++)	A[i]/=gd;
	for(int i=2;i<=MAXN;i++){
		if(!vis[i]) pri[++cnt]=i,fs[i]=i;
		for(int j=1;j<=cnt&&pri[j]*i<=MAXN;j++){
			vis[i*pri[j]]=1,fs[i*pri[j]]=pri[j];
			if(i%pri[j]==0) break;
		} 
	}
	for(int i=1;i<=n;i++){
		ct+=(A[i]==1); int now=fs[A[i]];
		while(A[i]!=1){while(A[i]%now==0) A[i]/=now;F[now]++,now=fs[A[i]];}
	}
	if(ct==n){puts("-1"); return 0;}
	for(int i=2;i<=MAXN;i++) ans=min(ans,n-ct-F[i]);
	ans+=ct,printf("%d\n",ans);	return 0;
}