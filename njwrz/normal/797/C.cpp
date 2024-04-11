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
V<char> v;
V<char> ans;
char c[100005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	scanf("%s",c+1);
	int n=strlen(c+1),l=1;
	FOR(now,0,25){
		V<int> nv;
		FOR(i,l,n){
			if(c[i]==now+'a')nv.PB(i);
		}
		while(!v.empty()&&v.back()<=now+'a')ans.PB(v.back()),v.pop_back();
		if(!nv.empty()){
			FOR(i,l,nv.back()){
				if(c[i]==now+'a'){
					ans.PB(c[i]);
				}else v.PB(c[i]);
			}
			l=nv.back()+1;
		}
	}
	for(auto u:ans)cout<<u;
	RE 0;
}