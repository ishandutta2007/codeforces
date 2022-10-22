#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int a[7005],b[7005];
V<int> c;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	map<int,int> m; 
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		if(m.count(a[i])){
			if(m[a[i]]==0){
				c.PB(a[i]);m[a[i]]=1;
			}
		}else m[a[i]]=0;
	}
	FOR(i,1,n)cin>>b[i];
	int t,ans=0;
	FOR(i,1,n){
		for(auto &u:c){
			t=u&a[i];
			if(t==a[i]){
				ans=ans+b[i];break;
			}
		}
	}
	cout<<ans;
	RE 0;
}