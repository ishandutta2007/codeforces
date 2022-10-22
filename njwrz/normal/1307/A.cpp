#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int n,a[105];
void solve(){
	int m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	int ans=a[1];
	FOR(i,2,n){
		if(a[i]*(i-1)>m){
			ans=ans+m/(i-1);
			break;
		}
		ans+=a[i];
		m-=a[i]*(i-1);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}