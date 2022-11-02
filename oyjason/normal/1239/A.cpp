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
#define M 200020
inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
int n,m,F[M],G[M];
int main(){
	n=read(),m=read(),F[1]=2,G[1]=0,F[0]=2;
	for(int i=2;i<=max(n,m);i++){
		F[i]=add(F[i-1],G[i-1]);
		G[i]=add(G[i-2],F[i-2]);
	}
	printf("%d\n",mns(add(add(F[n],G[n]),add(F[m],G[m])),2));
	return 0;
}