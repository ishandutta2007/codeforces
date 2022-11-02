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
int n,ans[1005];
void solve(){
	cin>>n;
	int x;
	V<int> v;
	FOR(i,1,n){
		cin>>x;v.PB(ans[x]);
	}
	V<int> t=v;
	sort(ALL(t));
	t.erase(unique(ALL(t)),t.end());
	for(auto &u:v){
		u=lower_bound(ALL(t),u)-t.begin()+1;
	}
	cout<<t.size()<<'\n';
	for(auto u:v)cout<<u<<' ';
	cout<<'\n';
}
bool ss(int x){
	if(x<2)RE 0;
	for(int i=2;i*i<=x;i++)if(x%i==0)RE 0;
	RE 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0;
	FOR(i,2,31){
		if(ss(i)){
			cnt++;
			for(int j=i;j<=1000;j+=i)ans[j]=cnt;
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}