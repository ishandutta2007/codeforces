/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[1005];
bool ss(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)RE 0;
	}
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int cnt=0;
	FOR(i,1,n)cnt+=a[i]==1;
	bool f=0;
	int it=0;
	FOR(i,1,n)if(a[i]!=1&&ss(a[i]+1))f=1,it=i;
	cnt+=f;
	if(cnt>=2){
		V<int> ans;
		FOR(i,1,n){
			if(i==it||a[i]==1){
				ans.PB(i);
			}
		}
		cout<<ans.size()<<'\n';
		for(auto u:ans)cout<<a[u]<<' ';
		RE 0; 
	}
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(ss(a[i]+a[j])){
				cout<<2<<'\n';
				cout<<a[i]<<' '<<a[j];RE 0;
			}
		}
	}
	cout<<"1\n"<<a[1];
	RE 0;
}