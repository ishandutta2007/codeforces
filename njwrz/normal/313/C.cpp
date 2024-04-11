#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
ll a[2000005];
int main(){
	ll n;
	n=read();
	for(ll i=0;i<n;i++)a[i]=read();
	sort(a,a+n,greater<ll>());
	ll t=1,l=1,ans=0;
	while(t!=n)t=t<<2,l++;
	t=1;ll p=0;
	for(ll i=0;i<n;i++){
		ans=ans+l*a[i];
		p++;
		if(p==t)t*=4,l--;
	}
	cout<<ans;
	return 0;
}