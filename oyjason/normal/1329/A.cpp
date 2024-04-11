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
#define M 2000200
int n,m,len[M],tot,L[M],R[M],mx,p[M];
int main(){
	n=read(),m=read();
	LL tot=0;
	for(int i=1;i<=m;i++) len[i]=read(),tot+=len[i],mx=max(mx,i+len[i]-1);
	if(mx>n||tot<n){puts("-1");return 0;}
	R[m]=n-len[m]+1;
	for(int i=m-1;i>=1;i--) R[i]=min(R[i+1]-1,n-len[i]+1);
	int now=0;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+1;
		while(p[i]<R[i]&&mx<n&&p[i]<=now) ++p[i],++mx;
		now=max(now,p[i]+len[i]-1);
	}
	if(now<n){puts("-1");return 0;}
	for(int i=1;i<=m;i++)  printf("%d",p[i]),putchar(i<m?' ':'\n');

	return 0;
}