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
int a[1005],n,x;
void solve(){
	cin>>n>>x;
	int cnt=0;
	FOR(i,1,n){
		cin>>a[i];
		cnt+=a[i]&1; 
	}
	if(!cnt){
		cout<<"No\n";
	}else if(cnt==n){
		if(x&1){
			cout<<"Yes\n";
		}else cout<<"No\n";
	}else if(x==n){
		if(cnt&1){
			cout<<"Yes\n";
		}else cout<<"No\n";
	}else cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}