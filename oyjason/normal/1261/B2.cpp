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
#define M 200200
int n,m;
int p[M],cnt;
int L[M*30],R[M*30],sm[M*30],rt[M];
pii t[M];
inline void ins(int &x,int y,int l,int r,int pos){
	x=++cnt,sm[x]=sm[y]+1,L[x]=L[y],R[x]=R[y];
	if(l==r) return; int mid=((l+r)>>1);
	(pos<=mid)?ins(L[x],L[y],l,mid,pos):ins(R[x],R[y],mid+1,r,pos);
}
inline int fd(int x,int l,int r,int rk){
	if(l==r) return p[l]; int mid=((l+r)>>1);
	if(sm[L[x]]>=rk) return fd(L[x],l,mid,rk);
	return fd(R[x],mid+1,r,rk-sm[L[x]]);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) t[i]=mp(-(p[i]=read()),i);
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++) ins(rt[i],rt[i-1],1,n,t[i].second);
	for(int k,w,Cas=read();Cas;--Cas){
		k=read(),w=read();
		printf("%d\n",fd(rt[k],1,n,w));
	}
	return 0;
}