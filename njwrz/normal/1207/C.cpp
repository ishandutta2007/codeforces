#include <bits/stdc++.h>
#define ll long long
using namespace std;
void voi(){
	ll n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	ll l=10000000,r=-10;
	for(ll i=0;i<n;i++){
		if(s[i]=='0')continue;
		l=min(l,i);r=max(r,i);
	}
	if(r==-10){
		cout<<(n+1)*b+n*a<<'\n';return ;
	}
	ll last=l,ans=a+4*b;
	for(ll i=l+1;i<=r;i++){
		if(s[i]=='0')continue;
		if(i-last==1){
			ans=ans+a+2*b;last=i;continue;
		}
		ans=ans+min(2*a,(i-last-2)*b)+(i-last-2)*b;
		ans=ans+(i-last)*a+4*b;
		last=i;
	}
	ans=ans+2*a;
	ans=ans+(l-1)*(a+b)+(n-r)*(a+b);
	cout<<ans<<'\n';
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)voi();
	return 0;
}