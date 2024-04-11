#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef long long ll;
ll b[20],p[20];
ll n;

ll g(ll x){
	ll l=0,sum=0,ans=0;
	for(;x;b[++l]=x%10,x/=10);
	reverse(b+1,b+l+1);
	for(int i=1;i<=l;i++){
		if(i==l)
			ans+=(2*sum+b[i]-1)*b[i]/2;
		else
			ans+=p[l-i]*(2*sum+b[i]-1)*b[i]/2+p[l-i-1]*(b[i]*45*(l-i));
		sum+=b[i];
	}
	return ans;
}

ll f(ll x){
	ll ans=0;
	for(;x;ans+=x%10,x/=10);
	return ans;
}

int main(){
	cin>>n;
	p[0]=1;
	for(int i=1;i<=18;i++)
		p[i]=p[i-1]*10;
	ll l=1,r=1ll<<55;
	while(l<r){
		ll mid=(l+r)/2;
		if(g(mid)>=n)
			r=mid;
		else
			l=mid+1;
	}
	ll now=g(r);
	for(ll i=1;;i++){
		if(now==n){
			cout<<i<<' '<<r-1<<endl;
			return 0;
		}
		now-=f(i);
		while(now<n)
			now+=f(r++);
	}
	return 0;
}