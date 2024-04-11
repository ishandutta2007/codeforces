#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,m,ans;
int a[100001],b[100001];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,m) scanf("%d",b+i);
	int l=1,sum1=0,sum2=0;
	F(i,1,n){
		sum1+=a[i];
		while(sum2+b[l]<=sum1) sum2+=b[l] ,++l;
		if(sum2==sum1) ++ans, sum1=sum2=0;
	}
	printf("%d",ans);
	return 0;
}