#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll n,ll k,ll d1,ll d2){
	ll a,b,c,d[4];
	a=(d1*2+d2+k)/3;
	b=a-d1;
	c=b-d2;
	if(a+b+c!=k||a<0||b<0||c<0)return 0;
	d[1]=a;d[2]=b;d[3]=c;
	sort(d+1,d+1+3);
	n-=(d[3]-d[1])+(d[3]-d[2])+k;
	if(n<0||n%3) return 0;
	return 1;
}
int main(){
	ll n,k,d1,d2,p;
	cin>>p;
	for(ll i=0;i<p;i++){
		cin>>n>>k>>d1>>d2;
		bool ok=0;
		if(check(n,k,d1,d2)&&!ok)ok=1;
		if(check(n,k,-d1,d2)&&!ok)ok=1;
		if(check(n,k,d1,-d2)&&!ok)ok=1;
		if(check(n,k,-d1,-d2)&&!ok)ok=1;
		if(ok)cout<<"yes\n";else cout<<"no\n";
	}
	return 0;
}