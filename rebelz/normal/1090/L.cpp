#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll t,n,a,b,k;

int main(){
	t=readint(); n=readint(); a=readint(); b=readint(); k=readint();
	if(k>n){
		printf("0\n");
		return 0;
	}
	ll cnt=n-n/2;
	if(a<b) cnt=n-cnt;
	ll tot=cnt*max(a,b);
	ll num=(n/2)*b+(n-n/2)*a;
	ll ans=min(t,num/k);
	if(k>cnt) ans=min(ans,(num-tot)/(k-cnt));
	printf("%lld\n",ans);
	return 0;
}