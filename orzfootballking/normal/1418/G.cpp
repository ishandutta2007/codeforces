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
#define __int128_t unsigned long long
using namespace std;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock().now().time_since_epoch().count());
__int128_t rng128(){return (__int128_t)rng64()<<64|rng64();}
__int128_t p[500005][3],s[500005]; 
int n;
int a[500005];
map<__int128_t,int> m;
V<int> v[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		rep(j,0,2)p[i][j]=rng128();
		p[i][2]=p[i][0]^p[i][1];
	}
	int l=0;
	m[s[0]]=1;
	int ans=0;
	FOR(i,1,n){
		s[i]=s[i-1]^p[a[i]][v[a[i]].size()%3];
		v[a[i]].PB(i);
		if(v[a[i]].size()>=4){
			int to=v[a[i]][v[a[i]].size()-4];
			rep(j,l,to){
				m[s[j]]--;
			} 
			gmax(l,to);
		}
		ans+=m[s[i]];
//		cout<<m[s[i]]<<'\n';
		m[s[i]]++;
	}
	cout<<ans;
	RE 0;
}