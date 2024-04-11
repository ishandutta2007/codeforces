#include <bits/stdc++.h>
#define m 998244353
#define ll long long
#define N 1000010
using namespace std;
ll n,a[N],s=0,p[N];
int main(){
	ll i,u=0;
	p[0]=1;for(i=1;i<N;i++) p[i]=2*p[i-1]%m;
	cin>>n;for(i=1;i<=n;i++) cin>>a[i];
	s=u=(p[n-1]*a[1])%m;for(i=2;i<=n;i++) u=(u+p[n-i]*(a[i]-a[i-1]))%m,s=(s+u)%m;
	cout<<s;return 0;
}