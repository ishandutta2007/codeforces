#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,k,t1,t2,ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),k=(m>>1)+1;
	if(m<=2) ans=0;
	else{
		if(n>=m-1) ans=m-k;
		else if(n>=k) ans=n-k+1;
		else ans=0;
	}
	printf("%I64d\n",ans);
	return 0;
}