#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second
ll get_rand(ll l, ll r)
{
	ll aa=(rand()<<15)^(rand());
	return aa%(r-l+1)+l;
}
ll prime(ll x)
{
	for (ll i=2;i*i<=x;i++) if (x%i==0) return 0;
	return 1;
}
ll get_prime(ll l, ll r)
{
	ll a;
	while(true)
	{
		a=get_rand(l,r);
		if (prime(a)) return a;
	}
}
ll pr,ba;
string s;
ll cnt0[200001];
vector<pll> sect;
vector<ll> hashes;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll bow(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
int main()
{
	srand(time(NULL));
	pr=get_prime(1e9+7,2e9+14),ba=get_rand(27,pr-1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>s;
	j=0;
	for (i=1;i<=n;i++) 
	{
		cnt0[i]=cnt0[i-1]+(s[i-1]=='0');
		if (cnt0[i]>cnt0[i-1]) 
		{
			sect.push_back({j,i-1});
			j=i;
		}
	}
	sect.push_back({j,i-1});
	hashes.push_back(0);
	for (i=0;i<sect.size();i++)
	{
		hashes.push_back((hashes[i]*ba+(sect[i].se-sect[i].fi+1)%2)%pr);
	}
	cin>>m;
	for (t=1;t<=m;t++)
	{
		cin>>u>>v>>a;
		u--;
		v--;
		if (cnt0[u+a]-cnt0[u]-cnt0[v+a]+cnt0[v]){
		 cout<<"No\n"; continue;}
		if (!(cnt0[u+a]-cnt0[u])) {
			cout<<"Yes\n"; continue;
		}
		ll su1=cnt0[u],su2=cnt0[u+a];
		ll sv1=cnt0[v],sv2=cnt0[v+a];
		ll hu=(hashes[su2]-hashes[su1+1]*bow(ba,su2-su1-1,pr)%pr+pr)%pr;
		ll hv=(hashes[sv2]-hashes[sv1+1]*bow(ba,sv2-sv1-1,pr)%pr+pr)%pr;
	//	cout<<hu<<' '<<hv<<endl;
		if ((hu==hv)and((sect[su1].se-u)%2==(sect[sv1].se-v)%2)and((u+a-sect[su2].fi)%2==(v+a-sect[sv2].fi)%2)) cout<<"Yes\n";
		else cout<<"No\n";
	}
}