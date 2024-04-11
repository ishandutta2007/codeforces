#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(itn i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=0; 
const ll mod=(ll)1e9+7;
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	cout<<quick((quick(2,m)-1)+mod,n);
}