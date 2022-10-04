#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)

int n,q,m,k;
int a[300005];

int x[31];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i),a[i]^=a[i-1];
	if(!a[n])return puts("-1"),0;
	F(i,1,n){
		int y=a[i];
		dF(j,30,0)if(y>>j&1){
			if(!x[j]){x[j]=y;break;}
			y^=x[j];
		}
	}
	int c=0;
	F(j,0,30)if(x[j])++c;
	printf("%d\n",c);
	return 0;
}