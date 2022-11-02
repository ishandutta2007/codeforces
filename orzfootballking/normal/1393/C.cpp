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
int cnt[100005];
int n;
V<int> v;
bool check(int x){
	int maxi,t;
	if(n%x==0){
		t=n/x;
		maxi=x;
	}else{
		t=n/x+1;
		maxi=n%x;
	}
	for(auto u:v){
		if(u>t)RE 0;
		if(u==t)maxi--;
	}
	if(maxi<0)RE 0;
	else RE 1;
}
void solve(){
	FILL(cnt,0);
	int x;v.clear();
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		cnt[x]++;
	}
	FOR(i,1,100000){
		if(cnt[i]>1)v.PB(cnt[i]);
	}
	sort(ALL(v));reverse(ALL(v));
	int l=1,r=n-1,mid,ans=1;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans-1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}