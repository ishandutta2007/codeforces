#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<int> a;
int check(int p){
	rep(i,1,a.size()){
		if(a[i]!=-1&&a[i-1]!=-1){
			if(abs(a[i]-a[i-1])>p)RE -1;
		}
	}
	int l=0,r=1e9;
	rep(i,0,a.size()){
		if(a[i]==-1){
			if(i){
				l=max(l,a[i-1]-p);
				r=min(r,a[i-1]+p);
			}
			if(i<a.size()-1){
				l=max(l,a[i+1]-p);
				r=min(r,a[i+1]+p);
			}
			if(r<l)RE -1;
		}
	}
	RE r;
}
void solve(){
	a.clear();
	int n,x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		if(!a.size()||a.back()!=x)a.PB(x);
	}
	int l=0,r=1e9,mid,ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)!=-1){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
	cout<<ans<<' '<<check(ans)<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}