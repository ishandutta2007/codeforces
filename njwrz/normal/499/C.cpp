#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll x1,y1,x2,y2,a,b,c,n,ans=0;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a>>b>>c;
		ans+=(a*x1+b*y1+c<0)^((a*x2+b*y2+c<0));
	}
	cout<<ans;
	return 0;
}