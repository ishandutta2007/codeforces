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
int n,x;
int a[505];
void solve(){
	cin>>n>>x;
	FOR(i,1,n)cin>>a[i];
	bool f=0;
	FOR(i,1,n){
		if(a[i]<a[i-1]){
			f=1;break;
		}
	}
	if(!f){
		cout<<"0\n";RE;
	}
	int cnt=0,l=1;
	FOR(i,1,n){
		if(a[i]<a[i-1]){
			FOR(j,l,i){
				if(a[j]>x){
					swap(x,a[j]);
					cnt++;
				}
			}
			l=i+1;
		}
		if(a[i]<a[i-1]){
			cout<<"-1\n";RE;
		}
	}
	cout<<cnt<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}