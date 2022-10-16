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
#define MAX 2000010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

int arr[MAX];

struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval, mx;						 											// TOD add new types if needed
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval, ll mx) : mx(mx), l(l), r(r), val(val), tagval(tagval), tag(0){}	// TOD initialize new types as well 	
		void integrate(){								   										// TOD for merging tag value to node value
			  
		}
		node operator+(node other){																// TOD for merging 2 node values (children to parent) !!!order matters!!!
			return node(l, other.r, val + other.val,0, max(mx, other.mx)) ;									
		}
		void operator+=(node& other){															// TOD for merging 2 tag values  (merge query to node)
			
		}
		void operator*=(node& other){															// TOD for queries (merging a segtree node to a query)
			val+=other.val;
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			//TOD	 lazy[num] = node ( proper initial values ) 
			lazy[num] = node(l,r,arr[l], 0, arr[l]);
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
		// TOD update the tag values
	}
	
	void upd(ll num, node& b){
		if(lazy[num].l > b.r || lazy[num].r < b.l)
			return;
		if(lazy[num].l >= b.l && lazy[num].r<=b.r && lazy[num].mx < b.tagval && b.val!=-1)
			return;
		if(lazy[num].l == lazy[num].r){
			lazy[num].val %= b.tagval;
			lazy[num].mx = lazy[num].val;
			if (b.val == -1)  lazy[num].val = lazy[num].mx = b.tagval;
			return;
		}
		upd(num<<1, b),		upd((num<<1)|1, b);
		pull(num); 
	}
	
	void que(ll num, node& b){ 				
	//	cout<<" so at "<<lazy[num].l<<" "<<lazy[num].r<<" the sum: "<<lazy[num].val<<endl;			
		if(lazy[num].l > b.r || lazy[num].r < b.l)		return ; 
		if(lazy[num].tag)								push(num);
		if(lazy[num].l >= b.l && lazy[num].r<=b.r){		b *= lazy[num]; return; }
		que(num<<1, b) , que((num<<1)|1, b);
	}
	
	~Segtree(){ delete[] lazy; }
};

void deal(){
	// u ll have to modify "node" struct accordingly
	// usage : 
	// Segtree lz
	// lz.init(1,1,n);
	// Segtree::node query( you probably want the update range l,r here , no base value, a tagvalue of the update ), 	    lz.upd( 1, query );
	// Segtree::node query(  you probably want the query range l,r here, a base value, no tag value ),						lz.que(1, query ), 	cout<<query.val;
	int n,m;
	cin>>n>>m;
	fori(n)
		cin>>arr[i+1];
	Segtree lz;
	lz.init(1, 1, n);
	fori(m){
		int ty;
		cin>>ty;
		if(ty == 1){
			int l,r;
			cin>>l>>r;
			Segtree::node query(l, r, 0, 0, 0);
			lz.que(1, query);
			cout<<query.val<<'\n';
		}
		else if(ty == 2){
			int l, r , x;
			cin>>l>>r>>x;
			Segtree::node query(l, r, 0, x, 0);
			lz.upd(1, query);
		}
		else{
			int ind, x;
			cin>>ind>>x;
			Segtree::node query(ind, ind, -1, x, 0);
			lz.upd(1, query);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}