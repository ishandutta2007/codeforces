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
int t[100005],a[100005],n; 
V<P<int,int> > ans;
int vis[100005],lst[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n){
		if(!vis[i]){
			lst[i]=i;
			for(int j=i+i;j<=n;j+=i)vis[j]=1;
		}else lst[i]=lst[i-1];
	}
	FOR(i,1,n){
		cin>>a[i];
		t[a[i]]=i;
	}
	int p,now;
	FOR(i,1,n){
		while(t[i]!=i){
			p=lst[t[i]-i+1];
			p=t[i]-p+1;
			ans.PB(MP(p,t[i]));
			swap(t[i],t[a[p]]);
			swap(a[t[i]],a[t[a[p]]]);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans){
		cout<<u.F<<' '<<u.S<<'\n';
	}
	RE 0;
}