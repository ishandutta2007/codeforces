#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define LL long long

LL n,l[N],w[N],g[N],ans;
char s[N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",l+i);
	scanf("%s",s+1);
	for (LL i=1,j=0,k=0,d=100;i<=n;++i){
		if (s[i]=='L'){
			LL &x=l[i];
			for (;j;--j){
				LL &y=l[w[j]];
				if (y<x){x-=y; ans+=y*4; y=0;}
				else{ans+=x*4; y-=x; x=0; break;}
			}
			for (;k;--k){
				LL &y=l[g[k]];
				if (y<x){x-=y; ans+=y*6; y=0;}
				else{ans+=x*6; y-=x; x=0; break;}
			}
			ans+=x*d;
		}
		if (s[i]=='W'){d=min(d,4LL); w[++j]=i;}
		if (s[i]=='G'){d=min(d,6LL); g[++k]=i;}
	}
	for (LL i=1,j=1;i<=n;++i)
		if (s[i]=='G'){
			LL x=l[i];
			if (x){
				for (;j<=i;++j)
					if (s[j]=='W'){
						if (l[j]<x){x-=l[j]; ans+=l[j]*4; l[j]=0;}
						else{ans+=x*4; l[j]-=x; x=0;}
						if (!x) break;
					}
			}
			ans+=x*3;
		}
	for (LL i=1;i<=n;++i)
		if (s[i]=='W') ans+=l[i]*2;
	printf("%lld\n",ans);
	
	return 0;
}