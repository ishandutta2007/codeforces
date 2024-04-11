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
int n,a[1005];
map<int,int> m,t;
map<P<int,int>,int> f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		m[a[i]]++;
	}
	int ans=max(m[0],2),x,y,z,ant;
	sort(a+1,a+n+1);
	FOR(i,1,n){
		FOR(j,1,n){
			if(i==j||(!a[i]&&!a[j]))continue;
			if(f.count(MP(a[i],a[j])))continue;
			f[MP(a[i],a[j])]=1;
			t.clear();
			t[a[i]]++;t[a[j]]++;
			x=a[i];y=a[j];z=x+y;
			ant=2;
			while(t[z]<m[z]){
				t[z]++;ant++;
				x=y;y=z;z=x+y;
			}
			ans=max(ans,ant);
		}
	}
	cout<<ans;
	RE 0;
}