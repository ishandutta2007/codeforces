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
int n,k,l1,r1,l2,r2;
void solve(){
	cin>>n>>k;
	cin>>l1>>r1>>l2>>r2;
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}
	int tl=max(l1,l2),tr=min(r1,r2);
	int de=tr-tl;
	gmax(de,0ll);
	if(de*n>=k){
		cout<<"0\n";RE;
	}
	k-=de*n;
	r1-=de;r2-=de;
	int ans=0,mini=1e18;
	FOR(i,1,n){
		int add=max(r1,r2)-l1;
		ans+=l2-l1+max(r1,r2)-min(r1,r2);
		if(add>=k){
			ans-=add-k;
			gmin(mini,ans);break;
		}else k-=add;
		gmin(mini,k*2+ans);
	}
	cout<<mini<<'\n'; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}