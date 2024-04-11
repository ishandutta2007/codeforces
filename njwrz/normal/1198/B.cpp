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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[200005],n,maxi[200005],last[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int x,y,q;
	cin>>q;
	FOR(i,1,q){
		cin>>x;
		if(x==1){
			cin>>x>>y;
			a[x]=y;
			last[x]=i;
		}else{
			cin>>maxi[i];
		}
	}
	for(int i=q-1;i>=0;i--)gmax(maxi[i],maxi[i+1]);
	FOR(i,1,n)gmax(a[i],maxi[last[i]]);
	FOR(i,1,n)cout<<a[i]<<" ";
	RE 0;
}