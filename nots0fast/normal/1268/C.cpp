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
#define MAX (int)(2*pow(10,6) + 10)


ifstream in;
ofstream out;
// #define cin in
// #define cout out

ll fen[MAX][2]; // 0 just for number of dudes, 1 - for sum of indices

void upd(ll ind, ll kd, ll vl){
	while(ind){
		fen[ind][kd]+=vl;
		ind-=ind&-ind;
	}
}

ll que(ll ind, ll kd){
	ll s = 0;
	while(ind<MAX){
		s+=fen[ind][kd];
		ind+=ind&-ind;
	}
	return s;
}

struct running_median{
	set<ll> one;
	set<ll> two;
	void ins(ll ed){
		if(one.size()){
			if(*one.rbegin() > ed){
				one.insert(ed);
				if(one.size() > two.size()){
					two.insert(*one.rbegin());
					auto it = one.end();
					--it;
					one.erase(it);
				}
				
			}
			else{
				two.insert(ed);
				if(two.size() > one.size()+1){
					one.insert(*two.begin());
					two.erase(two.begin());
				}
			}
		}
		else{
			two.insert(ed);
			if(two.size() > 1){
				one.insert(*two.begin());
				two.erase(two.begin());
			}
		}
	}
	ll median(){
		assert(two.size() > 0);
		return *two.begin();
	}
};

ll sum_1_to_i(ll i){
	return i*(i+1)/2;
}

void deal(){
	ll n;
	cin>>n;
	vector<pair<ll,ll> > all;
	fori(n){
		ll ed;
		cin>>ed;
		all.pb(mp(ed, i+1));
	}
	sort(all.begin(), all.end());
	ll sum_idx =  0;
	ll sum_inv = 0;
	running_median rmd;
	fori(all.size()){
		ll idx = all[i].ss;
		
		
		rmd.ins(idx);
		sum_idx += idx;
		sum_inv += que(idx, 0); // inversion
		upd(idx, 0, 1);
		upd(idx, 1, idx);
		
		
//		cout<<"sum of indices : "<<sum_idx<<" sum of inv "<<sum_inv;
		
		ll cur_median = rmd.median(); // median index
		ll on_the_right = que(cur_median, 0);
		ll sum_right = que(cur_median, 1);
		ll on_the_left = (i+1) - on_the_right;
		ll sum_left =  sum_idx - sum_right;
		
	//	cout<<"  the median "<<cur_median<<"   on the right(inclusive) "<<on_the_right<<" sum right "<< sum_right<<"  on_the_left "<<on_the_left<<" sum_left "<<sum_left<<endl;
		
		// also dont forget to subtract buildup
		ll tot = i;
		ll buildup = sum_1_to_i(tot/2) + sum_1_to_i(tot-tot/2);
//		cout<<"  buildup "<<buildup<<endl;
		
		ll ans = sum_inv + ( sum_right - cur_median * on_the_right) + (cur_median * on_the_left - sum_left) - buildup;
		
		
		cout<<ans<<' ';
		
		
	}
}

 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}