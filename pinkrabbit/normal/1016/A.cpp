#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int n,m;
int a[200001];

int main(){
	LL S=0; int lst=0;
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i), S+=a[i], printf("%d ",S/m-lst), lst=S/m;
	return 0;
}