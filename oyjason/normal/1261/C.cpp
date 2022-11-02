#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define uint unsigned int
#define ULL unsigned long long
#define LDB long double 
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(LL x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline LL read(){
		LL nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 3002000
int n,m,T[M],ans,W[M]; LL H[M];
char ch[M];
int *c[M],*p[M]; LL *w[M];
inline int qry(int x,int y,int rg){
	int rx=min(n,x+rg-1),ry=min(m,y+rg-1);
	return c[rx][ry]-c[x-1][ry]-c[rx][y-1]+c[x-1][y-1];
}
inline bool check(int rg){
	rg<<=1,++rg;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) w[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(qry(i,j,rg)==rg*rg) w[i][j]++,w[i+rg][j]--,w[i][j+rg]--,w[i+rg][j+rg]++;
		w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
		if(p[i][j]&&!w[i][j]) return false;
	} return true;
}
inline void opt(){
	printf("%d\n",ans);
	int rg=ans; rg<<=1,++rg;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) w[i][j]=0;
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++){
		if(qry(i,j,rg)==rg*rg) w[i+ans][j+ans]=1;
		if(w[i][j]) putchar('X'); else putchar('.');
	}
}
int main(){
	n=read(),m=read();
	for(int i=0;i<=n+1;i++) c[i]=T+i*(m+2),w[i]=H+i*(m+2),p[i]=W+i*(m+2);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++) c[i][j]=(p[i][j]=(ch[j]=='X'))+c[i][j-1];
		for(int j=1;j<=m;j++) c[i][j]+=c[i-1][j];
	}
	for(int l=1,r=((min(n,m)-1)>>1),mid=((l+r)>>1);l<=r;mid=((l+r)>>1))
		if(check(mid)) ans=mid,l=mid+1; else r=mid-1;
	opt();
	return 0;
}