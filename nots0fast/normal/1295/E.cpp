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
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;





struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval;						 											
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval) : l(l), r(r), val(val), tagval(tagval), tag(0){}	// TODO add additional types	
		void integrate(){	// TODO integrate tagvalue to node value
			val+=tagval;
		}
		node operator+(node other){		// TODO merge "val" of  children properly															
			return node(l, other.r, min(val, other.val) ,0);									
		}
		void operator+=(node& other){	// TODO merge 2 tag (existing tag, new tag) values 						
			// merge other's "tagval" to our "tagval" only !!!! otherwise need modification
			tagval+=other.tagval;
		}
		void operator*=(node& other){	// TODO merge node value to query value
			// merge other's "val" to our "val" only !!!! otherwise need modification
			val = min(val, other.val);
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			lazy[num] = node ( l, r, inf, 0 ); 
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
		if(lazy[num].l > b.r || lazy[num].r < b.l )
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
	ll t = 1;
//	cin>>t;
	while(t--){
		// u ll have to modify "node" struct accordingly
		// usage : 
		// Segtree lz
		// lz.init(1,1,n);
		// Updates:
		// Segtree::node query(l,r,0,tagval), lz.upd(1, query). !!! tagval is the update  ( so initialize it ) !!!
		// Queries:
		// Segtree::node query(l,r,val,   0), lz.que(1, query). !!! val    will be answer to query ( so initialize it ) !!
		Segtree lz;
		ll n ;
		cin>>n;
		vector<ll> arr(n);
		vector<ll> cst(n);
		fori(n){
			cin>>arr[i];
		}
		fori(n){
			cin>>cst[i];
		}
		lz.init(1,0,n);
		ll mn = inf;
		fori(n){
			ll ind = arr[i];
			Segtree::node updque(ind+1, n, 0, cst[i]);
			lz.upd(1, updque);
		}
		Segtree::node updquery(0,0, 0, -inf);
		lz.upd(1,updquery);
		fori(n-1){
			ll ind = arr[i];
			
			Segtree::node updquery1(0, ind-1, 0, cst[i]);
			lz.upd(1, updquery1);
			Segtree::node updquery2(ind+1, n, 0, -cst[i]);
			lz.upd(1, updquery2);
			Segtree::node updquery3(ind, ind, 0, -inf);
			lz.upd(1, updquery3);
			Segtree::node query(0, n, inf, 0);
			lz.que(1, query);
			mn = min(mn, query.val);
		//	cout<<" and query value is "<<query.val<<endl;
		}
		cout<<mn<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}