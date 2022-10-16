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
#define MAX 55
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9) + 7;

ll area(vector<pair<ll,ll> >& pol){
	ll sum = 0;
	ll n = pol.size();
	fori(pol.size())
		sum+=pol[i].ff*pol[(i+1)%n].ss - pol[(i+1)%n].ff*pol[i].ss;
	return fabs(sum);
}

ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a%b);
}
vector<pair<ll,ll> > all;
pair<ll,ll> line(pair<ll,ll>& a,pair<ll,ll>& b){
	ll dx1 , dy1, dx2, dy2;
	dx1  = b.ff - a.ff;
	dy1  = b.ss - a.ss;
	if(dx1!=0 && dy1!=0){
		ll ebob = gcd((ll)fabs(dx1), (ll)fabs(dy1));
		dx1 /= ebob, dy1 /= ebob;
	}
	if(dx1 < 0 )	dx1*=-1, dy1*=-1;
	if(dx1 == 0)	dx1 = inf*2 + 1, dy1 = a.ff;
	else if(dy1 == 0)	dy1 = inf*2+1 , dx1 = a.ss;
//	cout<<dx1<<" "<<dy1<<endl;
	return pair<ll,ll> {dx1,dy1};
}
void deal(){
	ll n ;
	cin>>n;
	all.resize(n);
	fori(n)	
		cin>>all[i].ff>>all[i].ss;
	vector<ll> indices(3);
	vector<pair<ll,ll> > chosen(3);
	indices[0] = 0, indices[1] = 1;
	chosen[0]  = all[0], chosen[1] = all[1];
	for(ll i = 2; i<n; i++)
		if(line(all[0], all[i]) != line(all[0], all[1])){
			indices[2] = i;
			chosen[2] = all[i];
			break;
		}
	fori(n){
		ll s = 0;
		ll area1 = area(chosen);
		forj(3){
			swap(chosen[j], all[i]);
			s+=area(chosen);
			swap(chosen[j], all[i]);
		}
		if(s==area1){
			forj(3){
				ll sv = i;
				swap(chosen[j], all[i]);
				swap(indices[j], sv);
				area1 = area(chosen);
				if(area1!=0)
					break;
				swap(indices[j], sv);
				swap(chosen[j], all[i]);
			}
		}
	}
	forj(3)
		cout<<indices[j]+1<<" ";
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 


*/