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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
ll a[4]={0,2,3,1};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,id,x[3];
		scanf("%lld",&n);
		id=n/3;
		if(n%3)++id;
		--id;
		int cnt=0;
		while(1ll<<(cnt<<1)<=n)++cnt;
		cnt*=2;
		x[0]=1ll<<cnt-2;
		x[1]=1ll<<cnt-1;
		id-=((1ll<<cnt-2)-1)/3;
		x[0]+=id;
		int len=0;
		while(id){
			x[1]+=a[id&3]<<len;
			id>>=2;
			len+=2;
		}
		x[2]=x[0]^x[1];
		printf("%lld\n\n",x[(n-1)%3]);
	}
}