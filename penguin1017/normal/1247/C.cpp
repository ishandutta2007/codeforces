#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
int table[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int count(int n){
	int ans=0;
	while(n){
		ans+=table[n&15];
		n>>=4;
	}
	return ans;
}
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=32;i++){
		int k=-i*p,sum;
		if(n+k<=0)break;
		sum=count(n+k);
		if(sum<=i&&n+k>=i){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}