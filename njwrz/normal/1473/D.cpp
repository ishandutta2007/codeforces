/*

DP





ll int
 dp 










*/
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
int maxil[200005],minil[200005],maxir[200005],minir[200005];
int p[200005];
void solve(){
	int n;
	cin>>n;
	int q;
	cin>>q;
	FOR(i,1,n){
		char c;
		cin>>c;
		if(c=='-'){
			p[i]=-1;
		}else p[i]=1;
	}
	FOR(i,1,n){
		p[i]+=p[i-1];
		maxil[i]=minil[i]=maxir[i]=minir[i]=p[i];
	}
	maxil[n+1]=minil[n+1]=maxir[n+1]=minir[n+1]=p[n];
	FOR(i,1,n){
		gmax(maxil[i],maxil[i-1]);
		gmin(minil[i],minil[i-1]);
	}
	for(int i=n;i>=1;i--){
		gmax(maxir[i],maxir[i+1]);
		gmin(minir[i],minir[i+1]);
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		cout<<max(maxil[l-1],maxir[r+1]-p[r]+p[l-1])-min(minil[l-1],minir[r+1]-p[r]+p[l-1])+1;
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}