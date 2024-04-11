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
bool check(int x){
	if(x==2){
		RE 0;
	}
	RE !(x&1);
}
void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"FastestFinger\n";
	}else if(n==2){
		cout<<"Ashishgup\n";
	}else if(n&1){
		cout<<"Ashishgup\n";
	}else{
		for(int i=2;i*i<=n;i++){
			if(n%i==0&&(check(i)&&((n/i)&1)||check(n/i)&&(i&1))){
				cout<<"Ashishgup\n";RE;
			}
		}
		cout<<"FastestFinger\n";
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