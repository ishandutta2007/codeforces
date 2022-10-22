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
	stack<int> p;
	int now=-1;
	bool lst=1;
	rep(i,0,s.size()){
		if(s[i]==t[0]&&(s.size()-i)%2==t.size()%2){
			now=i;break;
		}
	}
	if(now==-1){
		cout<<"NO\n";RE;
	}
	int ls=(now&1);
	rep(i,1,t.size()){
		now++;
		while(now<s.size()&&(s[now]!=t[i]||(now&1)==ls))now++;
		if(now>=s.size()){
			cout<<"NO\n";RE;
		}
		ls=now&1;
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}