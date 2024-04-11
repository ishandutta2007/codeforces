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
using namespace std;
int n,T,a[100005];
int cnt[30];
char c[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>T;
	FOR(i,1,n)cin>>c[i],a[i]=c[i]-'a';
	T-=1<<a[n];
	T+=1<<a[n-1];
	rep(i,1,n-1)cnt[a[i]]++;
	for(int i=25;i>=0;i--){
		int now=T-cnt[i]*(1<<i);
		for(int j=-cnt[i];j<=cnt[i];j+=2){
			if(abs(now)>abs(T-j*(1<<i))){
				now=T-j*(1<<i);
			}
		}
		T=now;
//		cout<<T<<'\n';
	}
	if(T){
		cout<<"No";
	}else cout<<"Yes";
	RE 0;
}