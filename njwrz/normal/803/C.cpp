/*

DP





ll int
 dp 










*/
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
int n,k;
void check(int x){
	int t=n/x;
	if(t*2/k<k+1)RE;
	rep(i,1,k){
		cout<<i*x<<' ';
	}
	cout<<(t-(k-1)*k/2)*x;exit(0);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	if(n*2/k<k+1){
		cout<<-1;RE 0;
	}
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			check(n/i);
		}
	}
	for(int i=sqrt(n);i>=1;i--){
		if(n%i==0){
			check(i);
		}
	}
	RE 0;
}