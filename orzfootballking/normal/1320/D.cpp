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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,s[200005],cnt[200005];
struct hash{
	int mod,h[200005][2],pw[200005],t=1e4+7;
	void solve(){
		FOR(i,1,n){
			h[i][0]=h[i-1][0];
			h[i][1]=h[i-1][1];
			if(!s[i]){
				h[i][0]=(h[i][0]*t+1+(i&1))%mod;
				h[i][1]=(h[i][1]*t+1+((i&1)^1))%mod;
			}
		}
		pw[0]=1;
		FOR(i,1,n)pw[i]=pw[i-1]*t%mod;
	}
	int check(int l,int r){
		RE ((h[r][l&1]-h[l-1][l&1]*pw[cnt[r]-cnt[l-1]])%mod+mod)%mod;
	}
}a,b;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c;
	cin>>n;
	FOR(i,1,n){
		cin>>c;
		s[i]=c-'0';
		cnt[i]=cnt[i-1]+(!s[i]);
	}
	a.mod=1e9+7;
	b.mod=998244353;
	a.solve();
	b.solve();
	int q,s1,s2,len;
	cin>>q;
	FOR(i,1,q){
		cin>>s1>>s2>>len;
		if(a.check(s1,s1+len-1)==a.check(s2,s2+len-1)&&b.check(s1,s1+len-1)==b.check(s2,s2+len-1)){
			cout<<"Yes\n";
		}else cout<<"No\n";
	}
	RE 0;
}