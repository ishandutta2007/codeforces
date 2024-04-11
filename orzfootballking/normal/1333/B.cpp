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
int a[100005],n,b[100005];
void solve(){
	bool f1,f2;
	f1=f2=0;
	int x;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,n){
		x=b[i];
		if(x<a[i]){
			if(!f2){
				cout<<"NO\n";RE;
			}
		}else if(x>a[i]){
			if(!f1){
				cout<<"NO\n";RE;
			}
		}
		if(a[i]==-1){
			f2=1;
		}else if(a[i]==1)f1=1;
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}