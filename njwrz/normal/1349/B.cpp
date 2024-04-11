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
int n,a[100005],k;
void solve(){
	cin>>n>>k;
	bool f=1;
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]==k)f=0;
	}
	if(f){
		cout<<"no\n";RE;
	}
	if(n==1){
		cout<<"yes\n";RE;
	}
	rep(i,1,n){
		if(a[i]>=k&&a[i+1]>=k){
			cout<<"yes\n";RE ;
		}
	}
	FOR(i,1,n-2){
		if(a[i]>=k&&a[i+2]>=k){
			cout<<"yes\n";RE;
		}
	}
	cout<<"no\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}