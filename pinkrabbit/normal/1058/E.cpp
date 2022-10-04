#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long LL;

int n;
LL a[500005], f[500005], s[500005], Ans;

int main(){
	LL x;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%lld",&x);
		while(x) x-=x&-x, ++a[i];
	}
	dF(i,n,1) f[i]=f[i+1]+(a[i]&1);
	dF(i,n,1) s[i]=s[i+1]+(f[i]&1);
	F(i,1,n){
		LL S=0, Max=0;
		int O=f[i]&1;
		LL Sum=0;
		F(j,i,n){
			S+=a[j], Max=max(Max,a[j]);
			if(S>=130) {Sum+=(O==1?(s[j+1]):(n-j+1-s[j+1])); break;}
			if(Max+Max<=S&&(f[j+1]&1)==O) ++Sum;
		}
		Ans+=Sum;
	} printf("%lld\n",Ans);
	return 0;
}