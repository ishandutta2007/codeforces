#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
V<int> v[100005];
int n,ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
	}
	int sum=0;
	FOR(i,1,m){
		sort(ALL(v[i]),greater<int>());
		sum=0;
		rep(j,0,v[i].size()){
			sum+=v[i][j];
			if(sum>0)ans[j+1]+=sum;else break;
		}
	}
	int maxi=0;
	FOR(i,1,n){
		maxi=max(maxi,ans[i]);
	}
	cout<<maxi;
	RE 0;
}