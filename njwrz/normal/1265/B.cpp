#pragma GCC optimize("Ofast,unroll-loops")
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
int c[200005];
void solve(){
	int n,x;
	cin>>n;
	FOR(i,1,n)c[i]=0;
	FOR(i,1,n){
		cin>>x;c[x]=i;
	}
	cout<<1;
	int l=c[1],r=l;
	FOR(i,2,n){
		l=min(l,c[i]);
		r=max(r,c[i]);
		if(r-l+1==i){
			cout<<1;
		}else cout<<0;
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}