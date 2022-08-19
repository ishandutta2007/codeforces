#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,inf;
ll a[1000005],tf[2100],f[2100][12],d[2100][12],cnt[12];
pll b[1000005];
vector<pll> vec;

ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}

void init(ll g){
	ll tmp=g;
	for(int i=2;i<=sqrt(tmp);i++){
		if(tmp%i==0){
			pll ps=mp(i,1);
			while(tmp%i==0) tmp/=i,ps.se*=i;
			vec.pb(ps);
		}
	}
	if(tmp>1) vec.pb(mp(tmp,tmp));
}

void dfs(ll now,ll num,int sub,int pos){
	if(pos==vec.size()) return (void)(tf[sub]=1);
	dfs(now,num,sub,pos+1);
	if(num<=k/cnt[pos]) dfs(now,num*cnt[pos],sub|(1<<pos),pos+1);
}

int main(){
	n=readint(); k=readint();
	ll g=0;
	for(int i=1;i<=n;i++) a[i]=readint(),g=gcd(g,a[i]);
	for(int i=1;i<=n;i++) b[i].se=readint();
	init(g);
	for(int i=1;i<=n;i++){
		ll ps=a[i]/g,nd=g;
		for(auto x:vec)
			while(ps%x.fi==0)
				ps/=x.fi,nd*=x.fi;
		b[i].fi=nd;
	}
	sort(b+1,b+n+1);
	memset(d,0x3f,sizeof(d));
	inf=d[0][0];
	d[0][0]=0;
	for(int i=1;i<=n;i++){
		if(b[i].fi!=b[i-1].fi){
			memset(tf,0,sizeof(tf));
			ll tmp=b[i].fi;
			for(int j=0;j<vec.size();j++){
				cnt[j]=1;
				while(tmp%vec[j].fi==0) tmp/=vec[j].fi,cnt[j]*=vec[j].fi;
			}
			dfs(b[i].fi,1,0,0);
			for(int j=0;j<vec.size();j++) for(int l=0;l<(1<<vec.size());l++) if(!(l&(1<<j))) tf[l]+=tf[l|(1<<j)];
			vector<int> op(0);
			for(int l=1;l<(1<<vec.size());l++) if(tf[l]==1) op.pb(l);
			for(int j=i;j<i+vec.size();j++){
				memcpy(f,d,sizeof(f[0])*(1<<vec.size()));
				for(auto t:op) for(int l=0;l<(1<<vec.size());l++) for(int p=0;p<vec.size();p++) chkmin(f[l|t][p+1],d[l][p]+b[j].se);
				memcpy(d,f,sizeof(d[0])*(1<<vec.size()));
				if(b[j].fi!=b[j+1].fi) break;
			}
			while(b[i].fi==b[i+1].fi) i++;
		}
	}
	ll ans=inf;
	for(int i=0;i<=vec.size();i++) if(d[(1<<vec.size())-1][i]!=inf) chkmin(ans,d[(1<<vec.size())-1][i]*i);
	printf("%lld\n",ans==inf?-1:ans);
	return 0;
}