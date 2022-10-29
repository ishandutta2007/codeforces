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
const int N=1e5+9;
const ll mod=998244353;
ll a[N<<1];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		scanf("%lld%lld",&n,&m);
		ll sum=0;
		rep(i,0,m){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		if(sum<n){
			printf("-1\n");
			continue;
		}
		ll L=n,R=sum-n;
		sort(a,a+m);
		int pos=m-1,ans=0;
		for(;pos>=0;--pos){
			if(a[pos]>L&&a[pos]>R){
				++ans;
				a[pos]>>=1;
				a[pos+1]=a[pos];
				pos+=2;
			}
			else if(a[pos]<=L&&a[pos]>R)L-=a[pos];
			else if(a[pos]>L&&a[pos]<=R)R-=a[pos];
			else{
				if(a[pos]&L)L-=a[pos];
				else if(a[pos]&R)R-=a[pos];
				else L-=a[pos];
			}
		}
		printf("%d\n",ans);
	}
}