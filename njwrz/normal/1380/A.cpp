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
int n,it[1005];
void solve(){
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		it[x]=i;
	}
	int l=1,r=n;
	for(int i=n;i>=1;i--){
		if(it[i]==l){
			l++;
		}else if(it[i]==r){
			r--;
		}else{
			cout<<"YES\n";
			rep(j,1,i){
				if(it[j]<it[i]){
					cout<<it[j]<<' ';break;
				}
			}
			cout<<it[i]<<' ';
			rep(j,1,i){
				if(it[j]>it[i]){
					cout<<it[j]<<' ';break;
				}
			}
			cout<<'\n';
			RE;
		}
	}
	cout<<"NO"<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}