#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int cnt;
ll get(ll n,ll len){
//	cout<<len<<"len\n";
	int last=1;
	ll res=len;
	rep(i,1,cnt){
		int temp;
		if(1ll<<(cnt-1-i)&n)temp=1;
		else temp=0; 
		res+=(temp-last)*((len)/(1ll<<i));
		last=temp;
	//	cout<<res<<"res\n";
	}
//	cout<<"ok\n";
	return res;
}
int main(){
	ll n,l,r;
	cin>>n>>l>>r;
	if(n==0){
		cout<<0;
		return 0;
	} 
	if(n==1){
		cout<<1;
		return 0;
	}
	while((1ll<<cnt)<=n)++cnt;
	ll sum=n-get(n,l-1)-get(n,(1ll<<cnt)-1-r);
	cout<<sum;
}