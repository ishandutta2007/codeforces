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
#define M 1202000

int n;
LL X[M],Y[M],sumx,sumy;

int main(){
	n=read();
	for(int i=1;i<=n;i++) X[i]=read(),Y[i]=read(),sumx+=X[i],sumy+=Y[i];
	if(n&1){puts("NO");return 0;}
	for(int a=1,b=(n>>1)+1;b<=n;a++,b++){
		if((X[a]+X[b])*(LL)(n>>1)!=sumx){puts("NO");return 0;}
		if((Y[a]+Y[b])*(LL)(n>>1)!=sumy){puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}