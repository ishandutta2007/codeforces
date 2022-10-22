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
bool f[105][105];
int a[105],mod=1e9+7,n;
struct matrix{
	int s[105][105];
	void clear(){
		FILL(s,0);
	}
	matrix mul(matrix &c){
		matrix re;
		re.clear();
		FOR(i,1,n){
			FOR(j,1,n){
				FOR(k,1,n){
					re.s[i][j]=(re.s[i][j]+s[i][k]*c.s[k][j])%mod;
				}
			}
		}
		RE re;
	}
};

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;k--;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		FOR(j,1,n){
			int t=a[i]^a[j];
			int cnt=0;
			FOR(k,0,60){
				if(t&(1ll<<k))cnt++;
			}
			if(cnt%3==0)f[i][j]=1;
		}
	}
	matrix t;
	t.clear();
	FOR(i,1,n)t.s[i][i]=1;
	matrix p;
	FOR(i,1,n){
		FOR(j,1,n)p.s[i][j]=f[i][j];
	}
	while(k){
		if(k&1)t=t.mul(p);
		p=p.mul(p);
		k/=2;
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,n)ans+=t.s[i][j];
	}
	cout<<ans%mod;
	RE 0;
}