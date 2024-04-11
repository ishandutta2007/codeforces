#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<(ll)v; i++)
#define forj(v) for(ll j=0; j<(ll)v; j++)
#define fork(v) for(ll k=0; k<(ll)v; k++)
#define forl(v) for(ll l=0; l<(ll)v; l++)
#define fort(v) for(ll t=0; t<(ll)v; t++)
#define forz(v) for(ll z=0; z<(ll)v; z++)
#define forx(v) for(ll x=0; x<(ll)v; x++)
#define fory(v) for(ll y=0; y<(ll)v; y++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 100)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,15);
ll modulo = 998244353;
ld eps = 1e-6;

ll Mn1[MAX];
ll Mn2[MAX];



struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval;						 											
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval) : l(l), r(r), val(val), tagval(tagval), tag(0){}	// TODO add additional types	
		void integrate(){	// TODO integrate tagvalue to node value
			val += tagval;
		}
		node operator+(node other){		// TODO merge "val" of  children properly															
			return node(l, other.r, max(val, other.val),0);									
		}
		void operator+=(node& other){	// TODO merge 2 tag (existing tag, new tag) values 						
			// merge other's "tagval" to our "tagval" only !!!! otherwise need modification
			tagval+=other.tagval;
		}
		void operator*=(node& other){	// TODO merge node value to query value
			// merge other's "val" to our "val" only !!!! otherwise need modification
			val = max(val, other.val);
		}
	};
	
	node* lazy = new node[1<<21];	
	void init(ll num, ll l , ll r){
		if(l==r){
			lazy[num] = node ( l, r, -Mn2[l], 0 );  
			return;
		}
		init((num<<1), l, (l+r)/2), init((num<<1)|1, (l+r)/2+1, r);
		lazy[num] = lazy[num<<1] + lazy[(num<<1)|1];
	}
	
	void pull(ll num){
		lazy[num] = lazy[num<<1] + lazy[(num<<1)|1];
	}
	
	void push(ll num){
		lazy[num].integrate();
		lazy[num].tag = 0;
		if(lazy[num].l != lazy[num].r){
			lazy[(num<<1)].tag = lazy[(num<<1)|1].tag = 1;
			lazy[(num<<1)] += lazy[num], lazy[(num<<1)|1]+=lazy[num];
		}
		lazy[num].tagval = 0; 
	}
	
	void upd(ll num, node& b){
		if(lazy[num].tag)	
			push(num);
		if(lazy[num].l > b.r || lazy[num].r < b.l)
			return;
		if(lazy[num].l >= b.l && lazy[num].r<=b.r){
			lazy[num] += b;
			push(num);
			return;
		}
		upd(num<<1, b),		upd((num<<1)|1, b);
		pull(num); 
	}
	
	void que(ll num, node& b){ 							
		if(lazy[num].l > b.r || lazy[num].r < b.l)		return ; 
		if(lazy[num].tag)								push(num);
		if(lazy[num].l >= b.l && lazy[num].r<=b.r){		b *= lazy[num]; return; }
		que(num<<1, b) , que((num<<1)|1, b);
	}
	
	~Segtree(){ delete[] lazy; }
};

void deal(){
	ll n, m, p;
	cin>>n>>m>>p;
	
	fori(MAX){
		Mn1[i] = inf;
		Mn2[i] = inf;
	}
	
	fori(n){
		ll a,b;
		cin>>a>>b;
		Mn1[a] = min(Mn1[a], b);
	}
	
	fori(m){
		ll a,b;
		cin>>a>>b;
		Mn2[a] = min(Mn2[a], b);
	}
	
//	cout<<"before modify"<<endl;
	for(ll i =MAX-2; i>-1; i--){
		Mn1[i] = min(Mn1[i], Mn1[i+1]);
		Mn2[i] = min(Mn2[i], Mn2[i+1]);
	}
	
	
	ll ans = -Mn1[0] - Mn2[0];
	
	map<ll, vector<pair<ll,ll> > > all;
	fori(p){
		ll a,b,c;
		cin>>a>>b>>c;
		all[a].pb(mp(b,c));
	}
	
	Segtree lz;
	lz.init(1, 0, MAX-1);
	
	
	
	for(auto& el : all){
	//	cout<<"we at x point "<<el.ff<<endl;
		forj(el.ss.size()){
			// do insertion to segtree 
			ll ind = el.ss[j].ff + 1;
			ll val = el.ss[j].ss;
			Segtree:: node query(ind, MAX-1, 0, val);
			lz.upd(1, query);
		}
		Segtree::node query(0, MAX-1, -inf,0);
		lz.que(1, query);
	//	cout<<"query value is "<<query.val<<" Mn1 is "<<Mn1[el.ff+1]<<endl;
		ans = max(ans, -Mn1[el.ff+1] + query.val);
	}
	cout<<ans;
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}