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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e6+1;
const ll mod=998244353;
int pri[N];
ll a[N/10];
vi g[N/4];
void pre(){
	for(int i=2;i<N;++i){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<N;++j){
			pri[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main(){
	
	//freopen("text.in","r",stdin);
	pre();
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",&a[i]);
	ll ans=n;
	rep(i,1,pri[0]+1){
		int val=pri[i];
		ll sum=0;
		rep(j,0,n){
			if(a[j]<val)sum+=val-a[j];
			else{
				ll last=a[j]%val;
				sum+=min(last,val-last);
			}
			if(sum>=ans)break;
		}
		ans=min(ans,sum);
	}
	ll l=a[0]-ans,r=a[0]+ans;
	l=max(l,(ll)N-1);
	rep(i,1,pri[0]+1){
		int p=pri[i];
		for(ll j=l/p*p+p;j<=r;j+=p){
			g[j-l].pb(p);
		}
	}
//	cout<<"ok\n";
	for(ll i=l+1;i<=r;++i){
		ll val=i;
		for(auto p:g[i-l]){
			while(val%p==0)val/=p;
		}
		if(val==1)continue;
		ll sum=0;
		rep(j,0,n){
			if(a[j]<val)sum+=val-a[j];
			else{
				ll last=a[j]%val;
				sum+=min(last,val-last);
			}
			if(sum>=ans)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}