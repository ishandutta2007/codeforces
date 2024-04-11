#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
int mod=1e9+7,cnt[30],tc[30],qz[30],inv[1000005],finv[1000005],f[1000005];
void sol(){
	inv[1]=1;
	f[1]=1;f[0]=1;
	finv[1]=1;finv[0]=1;
	FOR(i,2,1000000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int solve(string s){
	int t,ans=0,sum=s.size(),ant;
	FOR(i,1,26){
		tc[i]=cnt[i];
		qz[i]=qz[i-1]+tc[i];
	}
	rep(i,0,s.size()){
		ant=qz[s[i]-'a'];
		ant=ant*f[s.size()-i-1]%mod;
		FOR(j,1,26)ant=ant*finv[tc[j]]%mod;
		ans=(ans+ant)%mod;
		if(!tc[s[i]-'a'+1])break;
		tc[s[i]-'a'+1]--;
		FOR(j,s[i]-'a'+1,26)qz[j]--;
	}
	RE ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol();
	string s,t;
	cin>>s>>t;
	rep(i,0,s.size())cnt[s[i]-'a'+1]++;
	cout<<(solve(t)-solve(s)+2*mod-1)%mod;
	RE 0;
}