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
#define pb(a) push_back(a)
typedef double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)
#define sqrtn (int)(670)


bool by_second(pair<ll,ll>& a, pair<ll,ll>& b){
	return a.ss > b.ss;
}

void deal(){
	ll n ;
	cin>>n;
	map<ll, ll> all;
	fori(n){
		ll ed;
		cin>>ed;
		all[ed] ++;
	}
	ll idx = 0;
	vector<ll> vals;
	for(auto& el : all){
		vals.pb(el.ss);
	}
	sort(vals.begin(), vals.end());
	ll answer = 0 , side1 = 0;
	{
		ll sum = 0;
		for(ll smaller_side = 1; smaller_side <sqrtn; ++smaller_side){
			while(idx!=vals.size() && vals[idx] < smaller_side){
				sum+=vals[idx];
				++idx;
			}
			ll cur_sum = sum;
			cur_sum+=(vals.size() - idx) * smaller_side;
			if(cur_sum/smaller_side >= smaller_side){
				cur_sum = (cur_sum/smaller_side) * smaller_side;
				if(cur_sum > answer){
					answer = cur_sum;
					side1 = smaller_side;
				}
			}
		}
	}
	ll side2 = answer/side1;
	cout<<answer<<'\n'<<side1<<' '<<side2<<'\n';
	vector<vector<ll> > rec(side1, vector<ll> (side2));
	{
		ll x = 0, y = 0;
		vector<pair<ll,ll> > all1;
		for(auto& el : all){
			all1.pb(mp(el.ff, el.ss));
		}
		sort(all1.begin(), all1.end(), by_second);
		for(auto& el : all1){
			ll how_many = el.ss;
			if(how_many > side1){
				how_many = side1;
			}
			fori(how_many){
				rec[x][y] = el.ff;
				++x, ++y;
				x%=side1, y%=side2;
				if(x == 0){
					y = (y - side1 + 1 +side2) % side2;
				}
			}
		}
	}
	fori(side1){
		forj(side2){
			cout<<rec[i][j]<<' ';
		}
		cout<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}