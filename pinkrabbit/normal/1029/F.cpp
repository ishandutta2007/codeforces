#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a,b;
int fr[1000001],t,m;
LL Ans=1e16;

int main(){
	scanf("%I64d%I64d",&a,&b);
	for(int i=1;(LL)i*i<=a;++i) if(a%i==0) fr[++t]=i;
	for(int i=1;(LL)i*i<=a+b;++i) if((a+b)%i==0){
		while(m<t&&fr[m+1]<=i) ++m;
		if(a/fr[m]<=(a+b)/i) Ans=min(Ans,2*(i+(a+b)/i));
	}
	t=m=0;
	for(int i=1;(LL)i*i<=b;++i) if(b%i==0) fr[++t]=i;
	for(int i=1;(LL)i*i<=a+b;++i) if((a+b)%i==0){
		while(m<t&&fr[m+1]<=i) ++m;
		if(b/fr[m]<=(a+b)/i) Ans=min(Ans,2*(i+(a+b)/i));
	}
	printf("%I64d",Ans);
	return 0;
}