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
bool a[55][55];
bool h[55],l[55];
void solve(){
	int n,m;
	cin>>n>>m;
	FILL(h,0);FILL(l,0);
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j],h[i]|=a[i][j],l[j]|=a[i][j];
	int cnth,cntl;
	cnth=cntl=0;
	FOR(i,1,n)cnth+=h[i];
	FOR(i,1,m)cntl+=l[i];
	cnth=n-cnth;
	cntl=m-cntl;
	int t=min(cntl,cnth);
	if(t&1){
		cout<<"Ashish\n";
	}else cout<<"Vivek\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}