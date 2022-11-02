#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<P<int,string> > ans,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m){
		cout<<"NO";RE 0;
	}
	ans.PB(MP(m-1,"R"));
	rep(i,1,n){
		ans.PB(MP(1,"D"));
		ans.PB(MP(m-1,"LUD"));
		ans.PB(MP(m-1,"R"));
	}
	ans.PB(MP(n-1,"U"));
	ans.PB(MP(m-1,"L"));
	rep(i,0,ans.size()){
		if(ans[i].F)t.PB(ans[i]);
	}
	ans=t;
	rep(i,0,ans.size()){
		if(ans[i].F*ans[i].S.size()>=k){
			cout<<"YES\n";
			cout<<i+(k>=ans[i].S.size())+(k%ans[i].S.size()!=0)<<'\n';
			rep(j,0,i){
				cout<<ans[j].F<<' '<<ans[j].S<<'\n';
			}
			if(k>=ans[i].S.size())cout<<k/ans[i].S.size()<<' '<<ans[i].S<<'\n';
			if(k%ans[i].S.size()!=0)cout<<"1 "<<ans[i].S.substr(0,k%ans[i].S.size())<<'\n';
			RE 0;
		}
		k-=ans[i].F*ans[i].S.size();
	}
	RE 0;
}