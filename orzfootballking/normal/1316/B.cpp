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
int nxt[5005][5005];
int p[5005][5005];
string s;
void solve(){
	int n,ans1=1,r;
	cin>>n>>s;
	string ans=s,t,now=s,p;
	r=n-1;
	bool f=n&1;
	rep(i,1,n){
		t="";
		FOR(j,1,r)t+=now[j];
		p="";
		rep(j,r+1,n)p+=now[j];
		if(!f)p+=now[0];else p=now[0]+p;
		for(int j=0;j<p.size()/2;j++)swap(p[j],p[p.size()-1-j]);
		t+=p;
		if(t<ans){
			ans=t;ans1=i+1;
		}
		now=t;r--;
		f=1-f;
	}
	cout<<ans<<'\n'<<ans1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}