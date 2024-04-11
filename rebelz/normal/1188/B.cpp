#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,p,k;
map<ll,ll> b;
ll ans=0;
ll a[300005];

int main(){
	n=readint(); p=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		ans+=b[(a[i]*a[i]%p*a[i]%p*a[i]%p+p-k*a[i]%p)%p];
		b[(a[i]*a[i]%p*a[i]%p*a[i]%p+p-k*a[i]%p)%p]++;
	}
	cout<<ans<<endl;
	return 0;
}