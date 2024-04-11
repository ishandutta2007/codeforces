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
int n;
int a[2005];
int cnt[2005];
V<int> v[2005];
void solve(){
	cin>>n;n*=2;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,1000){
		rep(j,0,i)cnt[j]=0,v[j].clear();
		FOR(j,1,n)cnt[a[j]%i]++,v[a[j]%i].PB(j);
		int ans=0,cnp=0;
		rep(j,1,i/2){
			if(cnt[j]>cnt[i-j]){
				ans+=cnt[j]-cnt[i-j];
				rep(k,0,cnt[j]-cnt[i-j])v[j].pop_back();
			}else if(cnt[i-j]>cnt[j]){
				ans+=cnt[i-j]-cnt[j];
				rep(k,0,cnt[i-j]-cnt[j])v[i-j].pop_back();
			}
		}
		ans+=cnt[0]&1;
		if(cnt[0]&1)v[0].pop_back();
		if(!(i&1)){
			ans+=cnt[i/2]&1;
			if(cnt[i/2]&1)v[i/2].pop_back();
		}
		if(!ans||ans==2){
			if(!ans){
				FOR(j,0,i/2){
					if(!v[j].empty()){
						v[j].pop_back();v[(i-j)%i].pop_back();
						break;
					}
				}
			}
			while(!v[0].empty()){
				cout<<v[0].back()<<' ';
				v[0].pop_back();
				cout<<v[0].back()<<'\n';
				v[0].pop_back();
			}
			FOR(j,1,i/2){
				while(!v[j].empty()){
					cout<<v[j].back()<<' ';v[j].pop_back();
					cout<<v[i-j].back()<<'\n';
					v[i-j].pop_back();
				}
			}
			RE;
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