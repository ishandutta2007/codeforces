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
int arr1[MAX];
int arr2[MAX];


struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval;						 											// TOD add new types if needed
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval) : l(l), r(r), val(val), tagval(tagval), tag(0){}	// TOO initialize new types as well 	
		void integrate(){								   										// TDO for merging tag value to node value
			val = arr1[tagval];
		}
		node operator+(node other){																// TOD for merging 2 node values (children to parent) !!!order matters!!!
			return node(l, other.r, 0,0);									
		}
		void operator+=(node& other){															// TOD for merging 2 tag values 
			tagval = (l-other.l) + other.tagval;
		}
		void operator*=(node& other){															// TOD for queries (merging a segtree node to a query)
			val = other.val;
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			//TOD	 lazy[num] = node ( proper initial values ) 
			lazy[num] = node(l,l,arr2[l], 0);
			return;
		}
		init((num<<1), l, (l+r)/2), init((num<<1)|1, (l+r)/2+1, r);
		lazy[num] = lazy[num<<1] + lazy[(num<<1)|1];
	}
	
	void pull(ll num){
		lazy[num] = lazy[num<<1] + lazy[(num<<1)|1];
	}
	
	void push(ll num){
//		cout<<"we gon integrate "<<lazy[num].l<<" "<<lazy[num].r<<" now old value "<<lazy[num].val<<endl;
		lazy[num].integrate();
	//	cout<<"we gon integrate "<<lazy[num].l<<" "<<lazy[num].r<<" now new value "<<lazy[num].val<<endl;
		lazy[num].tag = 0;
		if(lazy[num].l != lazy[num].r){
			lazy[(num<<1)].tag = lazy[(num<<1)|1].tag = 1;
			lazy[(num<<1)] += lazy[num], lazy[(num<<1)|1]+=lazy[num];
		}
		// TOD update the tag values
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
	// u ll have to modify "node" struct accordingly
	// usage : 
	// Segtree lz
	// lz.init(1,1,n);
	// Segtree::node query( you probably want the update range l,r here , no base value, a tagvalue of the update ), 	    lz.upd( 1, query );
	// Segtree::node query(  you probably want the query range l,r here, a base value, no tag value ),						lz.que(1, query ), 	cout<<query.val;
	Segtree lz;
	int n,q;
	cin>>n>>q;
	fori(n)
		cin>>arr1[i+1];
	fori(n)
		cin>>arr2[i+1];
	lz.init(1,1,n);
	fori(q){
		int ty;
		cin>>ty;
		if(ty == 1){
			int x, y, k;
			cin>>x>>y>>k;
			Segtree::node query(y, y+k-1, 0, x);
			lz.upd(1, query);
		}
		else{
			int x;
			cin>>x;
			Segtree::node query(x,  x, 0, 0);
			lz.que(1, query);
			cout<<query.val<<'\n';
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}