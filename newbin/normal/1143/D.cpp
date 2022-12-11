#include <iostream>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
ll n,k,a,b;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

int main(){
    cin>>n>>k>>a>>b;
    ll mi=INF, ma=0;
    for (int i=0; i<=n; ++i){
    	ll l,t;
    	l=i*k-a-b;
    	if(l>0){
    		t=n*k/gcd(n*k,l);
    		mi=min(mi,t);
    		ma=max(ma,t);
		}
		
		l=i*k-a+b;
		if(l>0){
			t=n*k/gcd(n*k,l);
    		mi=min(mi,t);
    		ma=max(ma,t);
		}
		
		l=i*k+a-b;
		if(l>0){
			t=n*k/gcd(n*k,l);
    		mi=min(mi,t);
    		ma=max(ma,t);
		}
		
		l=i*k+a+b;
		if(l>0){
			t=n*k/gcd(n*k,l);
    		mi=min(mi,t);
    		ma=max(ma,t);
		}
    }
    cout<<mi<<" "<<ma<<endl;
}