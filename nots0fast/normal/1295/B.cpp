#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,7) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;

ll sum_dist(ll a, ll b, ll pt){
	return fabs(a-pt) + fabs(b-pt);
}
 
void deal(){
	ll t;
	cin>>t;
	while(t--){
		ll n, x;
		cin>>n>>x;
		string a;
		cin>>a;
		map<ll,ll> all;
		ll s = 0;
		all[s]++;
		ll mx = 0;
		ll mn = 0;
		fori(a.length()){
			if(a[i] == '0'){
				++s;
			}
			else{
				--s;
			}
			all[s]++;
			mx = max(mx, s);
			mn = min(mn, s);
		}
		if(!s){
			if(all[x]){
				cout<<"-1\n";
			}
			else{
				cout<<"0\n";
			}
			continue;
		}
		
		ll when ;
		if(all[x]){
			when = 0;
		}
		else{
			if(sum_dist(mn+s, mx+s, x) > sum_dist(mn, mx, x)){
				cout<<"0\n";
				continue;
			}
			ll lo = 0, hi = 1e9 + 10;
			while(lo < hi){
				ll mid = (lo+hi)/2+1;
				if(sum_dist(mn+mid*s, mx+mid*s, x) < sum_dist(mn+(mid-1)*s, mx+(mid-1)*s, x)){
					lo = mid;
				}
				else{
					hi = mid-1;
				}
			}
			when = lo-1;
		}
		ll act = x - when*s;
		if(!all[act]){
			act = x - (when+1)*s;
		}
		ll ans = 0;
		bool firsttime=  1;
		while(all[act]){
			ans+=all[act];
			act-=s;
			if(firsttime){
				firsttime=  0;
				all[0]--;
			}
		}
		cout<<ans<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}