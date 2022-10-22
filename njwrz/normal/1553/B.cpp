#pragma GCC optimize(2)
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
void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.size();
	rep(i,0,n){
		int now=0;
		rep(j,i,n){
			if(s[j]!=t[now])break;
			int tt=now+1,ti=j-1;
			bool ff=1;
			while(ti>=0&&tt<t.size()){
				if(s[ti]!=t[tt]){
					ff=0;break;
				}
				ti--;tt++;
			}
			if(tt==t.size()){
				cout<<"YES\n";RE;
			}
			now++;
		}
	}
	cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}