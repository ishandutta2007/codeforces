#include <bits/stdc++.h>
#define N (1<<20)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF (1LL<<30)
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	while(b){
		ll c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int n;
ll k;
ll a[1024];
map<ll,int> fm;
vector<pair<ll,int> > f;
vector<int> f2;
vector<vector<int> > df;
vector<ll> ds;

vector<pair<ll,vector<int> > > dss;

vector<ll> ps;
bool isp[N];

void gen(int k, ll cur){
	if(k==f.size()){dss.pb(mp(cur,f2));return;}
	f2[k]=0;
	gen(k+1,cur);
	ll cur2=cur;
	fore(i,0,f[k].snd){
		cur2*=f[k].fst;
		f2[k]=i+1;
		gen(k+1,cur2);
	}
}

void gendiv(ll x){
	memset(isp,true,sizeof(isp));
	fore(i,2,N){
		if(isp[i]){
			ps.pb(i);
			if(i<=(1<<14))for(int j=i*i;j<N;j+=i)isp[j]=false;
		}
	}
	for(int i=0;ps[i]*ps[i]<=x;++i){
		while(x%ps[i]==0){
			x/=ps[i];
			fm[ps[i]]++;
		}
	}
	if(x>1)fm[x]++;
	for(map<ll,int>::iterator it=fm.begin();it!=fm.end();++it)f.pb(mp(it->fst,it->snd)),f2.pb(0);
	gen(0,1);
	sort(dss.begin(),dss.end());
	fore(i,0,dss.size())ds.pb(dss[i].fst),df.pb(dss[i].snd);
/*
	fore(i,0,f.size())cout<<f[i].fst<<' '<<f[i].snd<<endl;
	fore(i,0,ds.size()){
		cout<<ds[i];
		fore(j,0,f.size())cout<<' '<<df[i][j];
		cout<<endl;
	}*/
}

int dp[1024][6796];
int ant[1024][6796];
ll dp2[1024][6796];
bool ch[1024][6796];
vector<int> sol;

ll gcdd(int i0, int i1){
	ll r=1;
	fore(i,0,f.size()){
		int m=min(df[i0][i],df[i1][i]);
		while(m--)r*=f[i].fst;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	if(k==1){
		cout<<1<<endl;
		ll m=0;
		fore(i,1,n)if(a[i]<a[m])m=i;
		cout<<m+1<<endl;
		return 0;
	}
	gendiv(k);

	fore(i,1,n+1){
		ll m=gcd(a[i-1],k);
		int mi=lower_bound(ds.begin(),ds.end(),m)-ds.begin();assert(ds[mi]==m);
		fore(j,1,ds.size()){
//			ll m=ds[j]/gcd(a[i-1],ds[j]);
			//cout<<a[i-1]<<' '<<ds[j]<<' '<<' '<<m<<endl;
//			int p=lower_bound(ds.begin(),ds.end(),m)-ds.begin();assert(ds[p]==m);
//			ant[i][j]=p;
			ll m=ds[j]/gcdd(mi,j);
			//cout<<a[i-1]<<' '<<ds[j]<<' '<<' '<<m<<endl;
			int p=lower_bound(ds.begin(),ds.end(),m)-ds.begin();assert(ds[p]==m);
			ant[i][j]=p;
		}
	}

	fore(j,1,ds.size())dp[0][j]=INF;
	fore(i,0,n+1)dp[i][0]=0;
	fore(i,1,n+1){
		fore(j,1,ds.size()){
			//ll m=ds[j]/gcd(a[i-1],ds[j]);
			//cout<<a[i-1]<<' '<<ds[j]<<' '<<' '<<m<<endl;
			//ll p=lower_bound(ds.begin(),ds.end(),m)-ds.begin();assert(ds[p]==m);
			dp[i][j]=min(dp[i-1][j],1+dp[i-1][ant[i][j]]);
		}
	}
	if(dp[n][ds.size()-1]>=INF){
		cout<<-1<<endl;
		return 0;
	}
	cout<<dp[n][ds.size()-1]<<endl;

	fore(i,0,n+1)dp2[i][0]=0;
	fore(i,1,n+1){
		fore(j,1,ds.size()){
			//ll m=ds[j]/gcd(a[i-1],ds[j]);
			//cout<<a[i-1]<<' '<<ds[j]<<' '<<' '<<m<<endl;
			//ll p=lower_bound(ds.begin(),ds.end(),m)-ds.begin();assert(ds[p]==m);
			dp2[i][j]=INF*INF;
			if(dp[i][j]==dp[i-1][j]){
				dp2[i][j]=dp2[i-1][j];
			}
			if(dp[i][j]==1+dp[i-1][ant[i][j]]&&a[i-1]+dp2[i-1][ant[i][j]]<dp2[i][j]){
				dp2[i][j]=a[i-1]+dp2[i-1][ant[i][j]];
				ch[i][j]=true;
			}
		}
	}
	int i=n,j=ds.size()-1;
	while(j){
		if(ch[i][j]){
			sol.pb(i);
			//ll m=ds[j]/gcd(a[i-1],ds[j]);
			//cout<<a[i-1]<<' '<<ds[j]<<' '<<' '<<m<<endl;
			j=ant[i][j];
		}
		i--;
	}
	cout<<sol[0];
	fore(i,1,sol.size())cout<<' '<<sol[i];
	cout<<endl;
	return 0;
}