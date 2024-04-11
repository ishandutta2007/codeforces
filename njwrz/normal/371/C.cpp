#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4],b[4],c[4],qian,zero=0;
bool check(ll p){
	ll x,y,z;
	x=a[1]*p;y=a[2]*p;z=a[3]*p;
	x-=b[1];y-=b[2];z-=b[3];
	x=max(zero,x*c[1]);
	y=max(zero,y*c[2]);
	z=max(zero,z*c[3]);
	return (x+y+z<=qian);
}
int main(){
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='B'){
			a[1]++;
		}else if(s[i]=='S'){
			a[2]++;
		}else a[3]++;
	}
	for(ll i=1;i<=3;i++)cin>>b[i];
	for(ll i=1;i<=3;i++)cin>>c[i];
	cin>>qian;
	ll l=0,r=10000000000000;
	while(r-l>5){
		ll mid=(r+l)>>1;
		if(check(mid)){
			l=mid;
		}else r=mid-1;
	}
	for(ll i=r;i>=l;i--){
		if(check(i)){
			cout<<i;return 0;
		}
	}
	return 0;
}