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
#define M 120200

int n,a[M],k,pos,ct[M];

int main(){
	n=read(),k=-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=0;j<30;j++) if((a[i]>>j)&1) ct[j]++;
	}
	for(int i=0;i<30;i++) if(ct[i]==1) k=i;
	for(int i=2;i<=n&&k>=0;i++) if((a[i]>>k)&1) swap(a[i],a[1]);
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}