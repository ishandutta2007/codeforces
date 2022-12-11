#include<iostream>
#define ll long long
using namespace std;
const int maxn = 3e5 + 50;
ll gcd(ll a,ll b){
	if(a < b) swap(a,b);
	while(a%b!=0){
		ll t = a%b;
		a = b;b = t;
	}return b;
}
ll x[maxn],p[maxn];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 1;i <= n;++i) cin>>x[i];
	for(int i = 1;i <= m;++i) cin>>p[i];
	ll t = x[2] - x[1];
	for(int i = 3;i <= n;++i){
		t = gcd(t,x[i] - x[i-1]);
	}
	int j = 0;
	for(int i = 1;i <= m;++i){
		if(t%p[i] == 0) {
			j = i;break;
		}
	}
	if(j) {
		cout<<"YES"<<endl;
		cout<<x[1]<<" "<<j<<endl;
	}
	else cout<<"NO"<<endl;
}