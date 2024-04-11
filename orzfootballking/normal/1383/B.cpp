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
int n,a[100005];
V<int> v[31];
void solve(){
	cin>>n;
	rep(i,0,31)v[i].clear();
	FOR(i,1,n){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j)){
				v[j].PB(a[i]);break;
			}
		}
	}
	for(int i=30;i>=0;i--){
		int len=v[i].size();
		if(len&1){
			int t=v[i].size()/2;
			if(!(t&1)||!(n&1)){
				cout<<"WIN\n";
			}else cout<<"LOSE\n";
			RE;
		}
		for(auto u:v[i]){
			u-=1<<i;
			for(int j=i-1;j>=0;j--){
				if(u&(1<<j)){
					v[j].PB(u);break;
				}
			}
		}
	}
	cout<<"DRAW\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}