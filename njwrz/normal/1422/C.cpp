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
string s;
int a[100005],p10[100005],mod=1e9+7,ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int n=s.size();
	FOR(i,1,n)a[i]=s[i-1]-'0';
	p10[0]=1;
	FOR(i,1,n)p10[i]=p10[i-1]*10%mod;
	FOR(i,1,n){
		ans[i]=(ans[i-1]+(i*p10[i-1]))%mod;
	}
	int sum=0;
	FOR(i,1,n){
		sum=(sum+((i-1)*i/2)%mod*p10[n-i]%mod*a[i])%mod;
		sum=(sum+ans[n-i]*a[i])%mod;
	}
	cout<<sum;
	RE 0;
}