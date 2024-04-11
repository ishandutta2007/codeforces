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
int a[505];
void solve(){
	cin>>n;
	V<int> v[2];
	FOR(i,1,n)cin>>a[i];
	int x;
	FOR(i,1,n){
		cin>>x;
		v[x].PB(a[i]);
	}
	if(!v[0].empty()&&!v[1].empty()){
		cout<<"Yes\n";
	}else{
		rep(i,1,n){
			if(a[i]>a[i+1]){
				cout<<"No\n";RE;
			}
		}
		cout<<"Yes\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}