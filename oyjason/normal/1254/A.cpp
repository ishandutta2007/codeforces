#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
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
#define M 202
int n,m,k,cnt,dn,k1,k2;
char ch[M][M];
int dx[M*M],dy[M*M],tot,c[M][M];
inline char calc(int x){
	x--;
	if(x<=9) return x+'0'; x-=10;
	if(x<=25) return x+'A'; x-=26;
	return x+'a';
}
inline void solve(){
	n=read(),m=read(),k=read(),cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(int j=1;j<=m;j++) cnt+=(ch[i][j]=='R');
		if(i&1){for(int j=1;j<=m;j++)++tot,dx[tot]=i,dy[tot]=j;}
		else{for(int j=m;j>=1;--j) ++tot,dx[tot]=i,dy[tot]=j;}
	}
	dn=cnt/k,k2=cnt%k,k1=k-k2; int bs=1;
	for(int tms=1;tms<=k;tms++){
		int rem=(k1>0?dn:(dn+1)); if(k1>0) --k1;
		if(tms==k) rem=n*m;
		while(bs<=n*m&&rem>0) rem-=(ch[dx[bs]][dy[bs]]=='R'),c[dx[bs]][dy[bs]]=tms,++bs;
	}
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=m;j++) putchar(calc(c[i][j]));
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();


	return 0;
}