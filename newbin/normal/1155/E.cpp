#include<iostream>
#define ll long long
using namespace std;
const ll mod = 1e6 + 3;
ll a[20][20];
int n = 11,m = 12;
bool guess(){
	for(int i = 0;i < n;++i){
		for(int j = i+1;j < n; ++j){//i+1
			while(a[j][i]){
				ll t = a[i][i]/a[j][i];
				for(int k = i;k < m;++k){
					a[i][k] = (a[i][k] - t*a[j][k])%mod;
					swap(a[i][k],a[j][k]);
				}
			}
		}
		if(!a[i][i]) return 0;
	}
	return 1;
}
ll ans[13];
ll qm(ll a,ll b){
	ll res = 1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res; 
}
int main(){
	for(ll i = 0;i <= 10;++i){
		cout<<"? "<<i<<endl<<flush;
		cin>>a[i][11];
		if(a[i][11] == 0){
			cout<<"! "<<i<<endl<<flush;return 0;
		}
		a[i][0] = 1;
		ll x = i;
		for(int j = 1;j < 11;++j) a[i][j] = x,x = x*i%mod;
	}
	if(!guess()){
		cout<<"! -1"<<endl<<flush;return 0;
	}
	for(int i = 10;i >= 0;--i){
		ll x = a[i][11];
		for(int j = 10;j > i; --j) x = (x - a[i][j]*ans[j])%mod;
		ans[i] = x*qm(a[i][i],mod-2)%mod;
	}
	for(ll x = 0;x < mod;++x){
		ll t = 1;
		ll res = 0;
		for(int i = 0;i < 11;++i){
			res = (res + t*ans[i])%mod;
			t = t*x%mod;
		}
		if(res == 0){
			cout<<"! "<<x<<endl<<flush;return 0;
		}
	}
	cout<<"! -1"<<endl<<flush;
}
/*
1
2
9
28
65
126
217
344
513
730
1001 
*/