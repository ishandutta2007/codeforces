/*

DP





ll int
 dp 










*/
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	FOR(i,1,q){
		int x;
		string s;
		cin>>x>>s;
		int t=x&-x;
		for(auto u:s){
			if(u=='U'){
				if(x!=n/2+1){
					t=t*2;
					if(x&t){
						x-=t/2;
					}else x+=t/2;
				}
			}else if(u=='L'){
				if(x&1)continue;
				x-=t/2;
				t=t/2;
			}else{
				if(x&1)continue;
				x+=t/2;
				t=t/2;
			}
		}
		cout<<x<<'\n';
	}
	RE 0;
}