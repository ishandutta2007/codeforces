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
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int> q;
	int n,x,t,ans=0;cin>>n>>t;
	FOR(i,1,n){
		cin>>x;
		while(!q.empty()&&q.top()>=t-i)q.pop();
		if(i<t&&x<t)q.emplace(x-i);
		gmax(ans,(int)q.size());
	}
	cout<<ans<<'\n';
	RE 0;
}