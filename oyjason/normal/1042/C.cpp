#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,P[M],G[M],ps,cst,tot,F[M],res;
int maxn=-1000000007;

void solve(){
	if((cst==n-1&&!res)||cst==n){
		if(cst==n-1) G[++cst]=ps;
		
		for(int i=1;i<=n;i++) if(P[i]==0){ps=i;break;}
		for(int i=1;i<=n;i++) if(i!=ps) printf("1 %d %d\n",G[i],G[ps]);
		exit(0);
	}
	for(int i=1;i<=n;i++)if((P[i]<0&&i!=ps)||(i==ps&&tot%2==0)) F[++res]=i;
}
int main(){
	n=read();
	
	
	for(int i=1;i<=n;i++){
		P[i]=read();
		if(P[i]<0){
			tot++;
			if(P[i]>maxn) maxn=P[i],ps=i;
		}
		else if(P[i]==0) G[++cst]=i;
		else if(P[i]>0) F[++res]=i;
	}
	
	solve();
	if(tot&1) G[++cst]=ps;
	
	
	for(int i=2;i<=cst;i++) printf("1 %d %d\n",G[i],G[1]);
	if(cst) printf("2 %d\n",G[1]);
	for(int i=2;i<=res;i++) printf("1 %d %d\n",F[i],F[1]);
}