#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int p1=133;
const int p2=233;
int n,a[100],table[1<<15],op=(1<<15)-1; 
map<ll,int> mp;
ll gethash(int cnt){
	ll hu1=1,hu2=1;
	rep(i,1,n){
		int sum=table[(a[i]^cnt)&op]-table[(a[0]^cnt)&op];
		hu1=(hu1*p1+sum)%mod;
		hu2=(hu2*p2+sum)%mod;
	}
	ll hu=(hu1<<30)+hu2;
	return hu;
}
ll gethash2(int cnt){
	ll hu1=1,hu2=1;
	rep(i,1,n){
		int sum=table[(a[0]^cnt)&op]-table[(a[i]^cnt)&op];
		hu1=(hu1*p1+sum)%mod;
		hu2=(hu2*p2+sum)%mod;
	}
	ll hu=(hu1<<30)+hu2;
	return hu;
}
int main()
{
	rep(i,0,(1<<14))table[i<<1]=table[i],table[i<<1|1]=table[i]+1;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	rep(i,0,(1<<15)){
		ll hu=gethash(i);
		mp[hu]=i;
	//	cout<<hu<<' '<<"check\n";
	//	system("pause");
	}
	rep(i,0,n)a[i]>>=15;
	rep(i,0,(1<<15)){
		ll hu=gethash2(i);
		if(mp.count(hu)){
		//	cout<<i<<' '<<hu<<' '<<mp[hu]<<"??\n";
			cout<<(i<<15|mp[hu]);
			return 0; 
		}
	}
	cout<<-1;
}