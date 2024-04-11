#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 100200
int n,m;
int lv[M],c[M];
int w[M];
int F[2020][2020],mx[M];
#define INF 1000000000
inline void upd(int x,int rem,int now){
	if(now<F[x][rem]) return; F[x][rem]=now;
	while(rem){
		rem>>=1,x++,now+=rem*w[x],F[x][rem]=max(F[x][rem],now);
		if(!rem) mx[x]=max(mx[x],now);
	}
}
inline void ins(int x,int cst){
	for(int i=n;i>=1;i--) if(F[x][i]>-INF) upd(x,i+1,F[x][i]-cst+w[x]);
	int pr=0; for(int i=1;i<=x;i++) pr=max(pr,mx[i]);
	upd(x,1,pr-cst+w[x]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) lv[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n+m;i++) w[i]=read();
	memset(F,-0x3f,sizeof(F));
	for(int i=1;i<=m+13;i++) F[i][0]=0;
	for(int i=n;i>=1;i--) ins(lv[i],c[i]);
	for(int i=1;i<=m+15;i++) mx[i]=max(mx[i],mx[i-1]);
	printf("%d\n",mx[m+15]);
	return 0;
}