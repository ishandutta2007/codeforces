#include <bits/stdc++.h>
using namespace std;
#define pd push_back
#define ve vector
#define ll long long 
#define qu queue
#define pq priority_queue
ll gcd(ll a,ll b){
	ll r;
	while(b!=0){
		r=a%b;
		a=b;b=r;
	}
	return a;
}
int main(){
	ll a,b,m,i,s1,s2,t1,t2,t,ans1,ans2;
	cin>>a>>b>>m;
	t=gcd(a,b);
	a=a/t;b=b/t;
	for(i=0;i<m;i++){
		cin>>s1>>s2>>t1>>t2;
		if(s1==1){
			ans1=s2/a+(s2%a!=0);
		}else ans1=s2/b+(s2%b!=0);
		if(t1==1){
			ans2=t2/a+(t2%a!=0);
		}else ans2=t2/b+(t2%b!=0);
		if(ans1==ans2){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	return 0;
}