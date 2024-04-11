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
int n;
bool check(int p,bool f){
	int t=n;
	t-=p+1;
	if(p<0)RE 1;
	int sum=1,now;
	FOR(i,1,p){
		now=min(sum,t/(p-i+1));
		sum+=now;
		t-=now*(p-i+1);
		if(f)cout<<now<<' ';
	}
	if(f)cout<<'\n';
	RE (t==0);
}
void solve(){
	cin>>n;
	int l=1,r=100000,ans,mid;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid,0)){
			r=mid-1;ans=mid;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
	check(ans,1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}