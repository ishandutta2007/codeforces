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
bool f[100005],p[100005];
V<int> v[100005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)f[i]=0,v[i].clear(),p[i]=0;
	int s,x;
	FOR(i,1,n){
		cin>>s;
		FOR(j,1,s){
			cin>>x;v[i].PB(x);
		}
	}
	int ans=0;
	FOR(i,1,n){
		for(auto u:v[i]){
			if(!f[u]){
				f[u]=1;p[i]=1;
				ans++;break;
			}
		}
	}
	if(ans==n){
		cout<<"OPTIMAL\n";
	} else{
		cout<<"IMPROVE\n";
		FOR(i,1,n){
			if(!p[i]){
				FOR(j,1,n){
					if(!f[j]){
						cout<<i<<' '<<j<<'\n';RE;
					}
				}
			}
		}
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