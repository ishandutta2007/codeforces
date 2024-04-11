#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
#define M 130020
bitset<1250010>F[52][26];
int be[M],sum,n,m,p[M];int las[26][M];
int main(){
	n=read();
	for(int i=1;i<=n+n;i++) p[i]=read();
	sort(p+1,p+n+n+1),reverse(p+1,p+n+n+1),be[n+n]=1; F[0][0][0]=true;
	for(int i=1;i<n+n-1;sum+=p[i++]){
		for(int j=0;j<=n-1;j++) F[i][j]=F[i-1][j];
		for(int j=1;j<=n-1;j++) F[i][j]|=(F[i-1][j-1]<<p[i]);
	} int bs=(sum>>1); while(!F[n+n-2][n-1][bs]) --bs;
	for(int k=n+n-2,rem=n-1;rem>0;--rem) for(int i=k;i>0;--i)
		if(p[i]<=bs&&F[i-1][rem-1][bs-p[i]]){k=i-1,bs-=p[i],be[i]=1;break;}
	for(int i=n-1;i>0;bs-=las[i][bs],i--) be[las[i][bs]]=1;
	for(int i=n+n;i>=1;i--) if(be[i]==1) printf("%d ",p[i]); puts("");
	for(int i=1;i<=n+n;i++) if(be[i]==0) printf("%d ",p[i]); puts("");
	return 0;
}