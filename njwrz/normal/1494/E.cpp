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
map<int,char> mp[200005];
int cnt1,cnt2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,m){
		char c;
		cin>>c;
		if(c=='+'){
			int x,y;
			cin>>x>>y>>c;
			mp[x][y]=c;
			if(mp[y][x]==c)cnt2++;
			if(mp[y][x]!=0)cnt1++;
		}else if(c=='-'){
			int x,y;
			cin>>x>>y;
			if(mp[y][x]==mp[x][y])cnt2--;
			if(mp[y][x]!=0)cnt1--;	
			mp[x][y]=0;
		}else{
			int k;
			cin>>k;
			if(k&1){
				cout<<(cnt1?"YES\n":"NO\n");
			}else cout<<(cnt2?"YES\n":"NO\n");
		}
	}
	RE 0;
}