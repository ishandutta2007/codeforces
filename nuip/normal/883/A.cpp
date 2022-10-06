#include <bits/stdc++.h>
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,b) reps(i,0,b)
#define pb push_back
#define all(c) c.begin(),c.end()
using namespace std;
using ll=long long;
const ll INF=2e18;
int main(){
	rep(_,1){
	ios_base::sync_with_stdio(0);
	ll n,m,d,a;
	// n=rand();
	// m=rand()%10+1;
	// d=rand();
	// a=rand();
	cin>>n>>m>>a>>d;
	vector<ll> ts(m);
	// rep(i,m) ts[i]=rand();
	// sort(all(ts));
	rep(i,m) cin>>ts[i];
	// ll bf=0;
	// {
	// 	auto v=ts;
	// 	rep(i,n) v.pb((i+1)*a);
	// 	sort(all(v));
	// 	ll cur=v[0]; ++bf;
	// 	while(1){
	// 		auto it=lower_bound(all(v),cur+d+1);
	// 		if(it==v.end()) break;
	// 		++bf;
	// 		cur=*it;
	// 	}
	// }
	ts.pb(INF); ++m;
	ll re=1;
	ll cur=min(a,ts[0]);
	ll one=d/a+1;
	//	cout<<one<<endl;
	while(1){
		//		cout<<cur<<","<<re<<endl;
		auto it=lower_bound(all(ts),cur+d+1);
		if(it==ts.end()){
			if(cur+d>=n*a) break;
			ll nxt=(cur+d)/a*a+a;
			//cout<<nxt<<":"<<re<<endl;
			assert(nxt<=n*a);
			ll t=a*n-nxt;
			//cout<<t<<endl;
			re+=((t+one-1)/a+one-1)/one;
			break;
		}
		ll x=*it;
		ll y=min(n*a+1,(cur+d)/a*a+a);
		if(y==n*a+1) y=x;
		if(cur%a==0 && y<=x){
			ll px=min(n,x/a)*a;
			if(px>=cur){
				ll ad=(px-cur)/a/one;
				re+=ad;
				//				cout<<cur<<"+="<<ad*one*a<<"("<<ad<<")"<<endl;
				cur+=ad*one*a;
			}
		}
		//			cout<<cur<<endl;
		it=lower_bound(all(ts),cur+d+1);
		if(it==ts.end()) break;
		x=*it;
		y=min(n*a+1,(cur+d)/a*a+a);
		if(y==n*a+1) y=x;
		cur=min(x,y);
		//				cout<<x<<","<<y<<":::"<<endl;
		++re;
	}
	//	cout<<"ans"<<endl;

	// if(bf!=re-1){
	// 	cout<<"expected "<<bf<<endl;
	// 	cout<<re-1<<endl;
	// 	cout<<n<<","<<m<<","<<a<<","<<d<<endl;
	// 	for(ll x:ts) cout<<x<<" ";cout<<endl;
	// 	return 0;
	// }
	cout<<re-1<<endl;
}
	return 0;
}
/*
expected 14073
14074
28145,2,9961,16827
491 2000000000000000000 

*/