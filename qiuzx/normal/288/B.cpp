#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll ksm(ll x,ll y){
	if(y==0) return 1;
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y&1) ret=(ret*x)%mod;
	return ret;
}
int main(){
	ll n,k;
	cin>>n>>k;
	cout<<(ksm(k,k-1)*ksm(n-k,n-k))%mod<<endl;
	return 0;
}