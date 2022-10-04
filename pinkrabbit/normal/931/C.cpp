#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int n;
ll a[100001];
ll sum,MX=-INF,MN=INF,MD;
int X1,X2,X3;
int Y1,Y2,Y3;
int ans=INF,A1,A2,A3;
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i), sum+=a[i], MX=max(MX,a[i]), MN=min(MN,a[i]);
	if(MX==MN||MX==MN+1){
		printf("%d\n",n);
		F(i,1,n) printf("%d ",a[i]);
		return 0;
	}
	MD=MX-1;
	F(i,1,n) if(a[i]==MN) ++X1; else if(a[i]==MD) ++X2; else ++X3;
	Y1=X1, Y2=X2, Y3=X3;
	int xxxx=min(X1,X3);
	X1-=xxxx, X3-=xxxx;
	X2+=xxxx+xxxx;
	while(X2>=0){
		if(ans>min(X1,Y1)+min(Y2,X2)+min(X3,Y3)){
			ans=min(X1,Y1)+min(Y2,X2)+min(X3,Y3);
			A1=X1, A2=X2, A3=X3;
		}
		X2-=2; ++X1, ++X3;
	}
	printf("%d\n",ans);
	F(i,1,A1) printf("%d ",MN);
	F(i,1,A2) printf("%d ",MD);
	F(i,1,A3) printf("%d ",MX);
	return 0;
}