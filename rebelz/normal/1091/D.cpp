#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
ll n,ans;
ll p[1000005],inv[1000005];

ll C(ll x,ll y){
	if(x<y) return 0;
	return (p[x]*inv[y]%cys)*inv[x-y]%cys;
}

ll power(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	p[0]=p[1]=1;
	for(int i=2;i<=n;i++) p[i]=p[i-1]*i%cys;
	for(int i=1;i<=n;i++) inv[i]=power(p[i],cys-2);
	ans=p[n];
	for(int i=1;i<=n-1;i++){
		ans=(ans+(p[n-i]-1)*C(n,i)%cys*p[i]%cys)%cys;
	}
	cout<<ans<<endl;
	return 0;
}