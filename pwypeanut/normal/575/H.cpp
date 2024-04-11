#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long expo(long long int a,int b){
	if(b==0)return 1LL;
	if(b==1)return a%mod;
	long long int v=expo(a,b/2);
	if(b%2)return (((v*v)%mod)*a)%mod;
	else return (v*v)%mod;
}

int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	long long cv=1;
	for(int i=1;i<=n+1;i++){
		cv*=(i+n);
		cv%=mod;
		cv*=expo((long long)i,mod-2);
		cv%=mod;
		ans+=cv;
		ans%=mod;
	}
	printf("%d\n",ans);
}