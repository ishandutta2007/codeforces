#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define pii pair<int,int>
#define ULL unsigned long long

#define LL long long
using namespace std;
namespace IO{
	const int BS=(1<<20)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
} using namespace IO;
#define M 1000200
int n,m,sum;
char ch[M]; int F[M],G[M],T[M];
inline int ID(int x,int y){return (x-1)*m+y;}
inline int typ(int x,int y){if(x<1||y<1||x>n||y>m)return -1;return ch[ID(x,y)]!='#';}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) scanf("%s",ch+1+(i-1)*m);
	if(n==1||m==1){
		for(int i=1;i<=n*m;i++) if(ch[i]=='#'){puts("0");return 0;}
		puts("1"); return 0;
	}  F[1]=G[n*m]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(F[ID(i,j)]){
		if(!typ(i,j)){F[ID(i,j)]=0;continue;}
		if(i<n) F[ID(i+1,j)]=1;
		if(j<m) F[ID(i,j+1)]=1;
	}
	for(int i=n;i>0;i--) for(int j=m;j>0;j--) if(G[ID(i,j)]){
		if(!typ(i,j)){G[ID(i,j)]=0;continue;}
		if(i>1) G[ID(i-1,j)]=1;
		if(j>1) G[ID(i,j-1)]=1;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(F[ID(i,j)]&G[ID(i,j)]) T[i+j]++;
	} int ans=2;
	for(int i=3;i<n+m;i++) ans=min(ans,T[i]);
	printf("%d\n",ans);
	return 0;
}