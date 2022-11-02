#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 4500
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,val[M],cnt[M],qs[M],Q[M],T,V[20];
int TOT,F[M][M],pos[M],MAXN,K,ans;
char ch[M];
int getnum(){
	int SUM=0;
	for(int i=0;i<n;i++) SUM+=((ch[i]-'0')<<i);
	return SUM;
}
int cmp(int x,int y){return val[x]<val[y];}
int getans(){
	int l=0,r=MAXN-1,fin=0,md;
	while(l<=r){
		md=(l+r>>1);
		if(val[pos[md]]<=K) fin=F[m][md],l=md+1;
		else r=md-1;
	}
	return fin;
}
int main(){
	n=read(),m=read(),T=read(),MAXN=(1<<n);
	for(int i=0;i<n;i++) V[i]=read(),TOT+=V[i];
	for(int i=0;i<MAXN;i++){
		pos[i]=i;
		for(int j=0;j<n;j++) val[i]+=((i>>j)&1)*V[j];
		val[i]=TOT-val[i];
	}
	sort(pos,pos+MAXN,cmp);
	for(int i=1;i<=m;i++) scanf("%s",ch),cnt[getnum()]++;
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			//printf("%d %d   val: %d\n",i,j,val[i^j]);
			F[i][j]=cnt[i^pos[j]];
			if(j) F[i][j]+=F[i][j-1];
		}
	}
	while(T--){
		scanf("%s",ch),m=getnum(),K=read();
		ans=getans(),printf("%d\n",ans);
	}
	return 0;
}
/*

2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60


1 2 4
100
0
1
0 0
0 100
1 0
1 100


*/