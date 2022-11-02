#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
ll p[250005],m,n;
int main(){
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*i%m;
	}
	ll ans=n*p[n]%m;
	for(ll i=1;i<n;i++){
		ll t=n-i;
		ans=ans+p[i+1]*t%m*t%m*p[t-1];ans=ans%m;
	}
	cout<<ans;
	RE 0;
}