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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e6+1;
const ll mod=998244353;
vi g[N];
int pri[N],count[N],pos[N],st[N],tot;
ll d[N*4],num[20],nn;
vi n,s;
vector<pii> np,sp;
void getprime(){//1e6 
	rep(i,2,N){
		if(!pri[i])pri[++pri[0]]=i,g[i].pb(i);
		for(int j=1;j<=pri[0]&&pri[j]*i<N;++j){
			pri[pri[j]*i]=1;
			g[pri[j]*i]=g[i];
			g[pri[j]*i].pb(pri[j]);
			if(i%pri[j]==0)break;
		} 
	}
}
ll get(ll m){//i 
	ll res=0;
	tot=0;
	int i=0,j=0;
	while(i<np.size()&&j<sp.size()){
		if(np[i].fi<sp[j].fi){
			num[tot++]=np[i].fi;
			++i;
		}
		else if(np[i].fi>sp[j].fi)++j;
		else{
			if(sp[j].se<np[i].se){
				ll a=1;
				rep(i,0,sp[j].se+1)a*=sp[j].fi;
				num[tot++]=a;
			}
			++i,++j;
		}
	}
	while(i<np.size()){
		num[tot++]=np[i].fi;
		++i;
	} 
	d[0]=1;
	res+=m; 
	rep(i,1,1<<tot){
		d[i]=d[i^(lb(i))]*num[pos[lb(i)]];
		if(st[i])res-=m/d[i];
		else res+=m/d[i];
	}
	return res;
}
ll dfs(ll d,int pos){//ii 
	if(pos==sp.size())return 1;
	if(sp[pos].fi*d>nn)return 1;
	ll res=0;
	rep(i,0,sp[pos].se+1){
		res+=dfs(d,pos+1);
		if(sp[pos].fi>nn/d)break;
		else d*=sp[pos].fi;
	}
	return res;
} 
int main(){
	getprime();
	rep(i,0,N)st[i]=st[i>>1]^(i&1);
	for(int i=0;(1<<i)<N;++i)pos[1<<i]=i;
	int t;
	scanf("%d",&t);
	int k=0,flag;
	while(t--){
		++k;
		ll n1,n2,n3,m1,m2,m3,s1,s2,s3;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n1,&n2,&n3,&m1,&m2,&m3,&s1,&s2,&s3);
		n.clear(),s.clear();
		for(auto v:g[n1])n.pb(v);
		for(auto v:g[n2])n.pb(v);
		for(auto v:g[n3])n.pb(v);
		s.pb(2);
		for(auto v:g[s1])s.pb(v);
		for(auto v:g[s2])s.pb(v);
		for(auto v:g[s3])s.pb(v);
		sort(all(n));
		sort(all(s));
		np.clear();
		if(n.size()){
			int p=n[0],cnt=0;
			rep(i,0,n.size()){
				if(n[i]!=p){
					np.pb({p,cnt});
					p=n[i],cnt=1;
				}
				else{
					++cnt;
				}
			}
			np.pb({p,cnt});
		}
		sp.clear();
		if(s.size()){
			int p=s[0],cnt=0;
			rep(i,0,s.size()){
				if(s[i]!=p){
					sp.pb({p,cnt});
					p=s[i],cnt=1;
				}
				else{
					++cnt;
				}
			}
			sp.pb({p,cnt});
		}
		ll ans=get(m1*m2*m3);
		nn=n1*n2*n3;
		ans+=dfs(1,0);
		printf("%lld\n",ans);
	}
}