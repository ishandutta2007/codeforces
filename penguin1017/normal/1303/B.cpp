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
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n,a,b;
		scanf("%lld%lld%lld",&n,&a,&b);
		if(a>=b){
			printf("%lld\n",n);
			continue;
		}
		ll half2,half=n/2;
		if(n&1)++half;
		half2=n-half;
		ll k=half/a,last=half%a;
		if(!last)--k;
		if(k*b<=half2){
			printf("%lld\n",n);
			continue;
		}
		ll ans=k*(a+b)+last;
		if(!last)ans+=a;
		printf("%lld\n",ans);
	}
}
/*
1658 654 985
*/