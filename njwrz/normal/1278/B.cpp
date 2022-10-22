#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,cha;
bool check(ll mid){
	ll t1=a,t2=b;
	for(ll i=mid;i>=1;i--){
		if(t1>t2){
			t2+=i;
		}else t1+=i;
	}
	return (t1==t2);
}
void solve(){
	cin>>a>>b;cha=abs(a-b);
	ll l=0,r=100000,mid;
	while(r-l>10){
		mid=(l+r)>>1;
		while((cha+(mid*(mid+1))/2)%2)mid++;
		if(check(mid)){
			r=mid;
		}else l=mid+1;
	}
	for(ll i=l;i<=r;i++){
		if(check(i)){
			cout<<i<<'\n';return ;
		}
	}
}
int main(){
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}