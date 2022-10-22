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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
bool f[1<<18];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	V<int> ans;
	f[x]=1;
	rep(i,1,(1<<n)){
		if(f[i])continue;
		ans.PB(i);
		f[x^i]=1;
	}
	cout<<ans.size()<<'\n';
	if(!ans.size())RE 0;
	cout<<ans[0]<<' ';
	rep(i,1,ans.size())cout<<(ans[i]^ans[i-1])<<' ';
	RE 0;
}