#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
const int INF=0x3f3f3f3f;
// from_luogu 2
int n,m,x,Ans;
int a[2001],b[2001],c[2001],d[2001];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i), a[i]+=a[i-1];
	F(i,1,m) scanf("%d",b+i), b[i]+=b[i-1];
	scanf("%d",&x);
	F(i,1,n) {c[i]=INF; F(j,1,n-i+1) c[i]=min(c[i],a[j+i-1]-a[j-1]);}
	F(i,1,m) {d[i]=INF; F(j,1,m-i+1) d[i]=min(d[i],b[j+i-1]-b[j-1]);}
	F(i,1,n) F(j,1,m) if((LL)c[i]*d[j]<=x) Ans=max(Ans,i*j);
	printf("%d",Ans);
	return 0;
}