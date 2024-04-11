#include<bits/stdc++.h>
using namespace std;

const int maxn=500007;
const long long mod=1e9+7;
long long n,m;

long long quick_power(long long a,long long b){
	long long ans=1,t=a;
	while (b){
		if (b&1) ans=(ans*t)%mod;
		b>>=1;
		t=(t*t)%mod;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	cout<<quick_power(((quick_power(2,m)-1)%mod+mod)%mod,n);
	return 0;
}