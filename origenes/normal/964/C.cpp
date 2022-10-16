#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000000+9;
const int maxk=123456;
ll n, a, b, k, ans;
char s[maxk];
ll fast_pow(ll x, ll k){
	ll ans=1;
	while(k){
		if(k&1){
			ans*=x;
			ans%=MOD;
		}
		x*=x;
		x%=MOD;
		k>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>a>>b>>k;
	scanf("%s", s);
	b=b*fast_pow(a, MOD-2)%MOD;
	for(int i=k-1; i>=0; i--){
		ll sign=(s[i]=='+'?1:MOD-1);
		ans=(ans*b+sign)%MOD;
	}
	b=fast_pow(b, k);
	n=(n+1)/k;
	if(b==1){
		ans*=n;
		ans%=MOD;
	}else{
		ans=ans*(fast_pow(b, n)-1)%MOD*fast_pow(b-1, MOD-2)%MOD;
	}
	ans*=fast_pow(a, n*k-1);
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<endl;
	return 0;
}