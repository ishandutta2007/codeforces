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

int n,top;
LDB sm[M]; int ct[M];
LL a[M];

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n;i>=1;i--){
		LDB sum=a[i]; int cnt=1;
		while(top>0&&sum*ct[top]>=sm[top]*cnt) sum+=sm[top],cnt+=ct[top],--top;
		++top,sm[top]=sum,ct[top]=cnt;
	}
	while(top){
		LDB arg=sm[top]/(LDB)ct[top];
		while(ct[top]--) printf("%.15Lf\n",arg);
		--top;
	}
	return 0;
}