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
ll MAX  = 2000010;
#define MAX2 300100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

ll arr1[MAX2];
deque<ll> occur[MAX2];
struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval;						 											
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval) : l(l), r(r), val(val), tagval(tagval), tag(0){}	// TODO add additional types	
		void integrate(){	
			val = tagval;
		}
		node operator+(node other){	
		//	cout<<val<<" "<<other.val<<endl;															
			return node(l, other.r, min(val,other.val),0);									
		}
		void operator+=(node& other){						
			tagval = other.tagval;
		}
		void operator*=(node& other){	
			val = min(val, other.val);
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			lazy[num] = node ( l,l, arr1[l],0 );  
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
ll arr[MAX2];
void deal(){
	// u ll have to modify "node" struct accordingly
	// usage : 
	// Segtree lz
	// lz.init(1,1,n);
	// Segtree::node query( you probably want the update range l,r here , no base value, a tagvalue of the update ), 	    lz.upd( 1, query );
	// Segtree::node query(  you probably want the query range l,r here, a base value, no tag value ),						lz.que(1, query ), 	cout<<query.val;
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		MAX= 4*n;
		fori(n)
			occur[i].clear();
		fori(n){
			ll ed;
			cin>>ed;
			--ed;
			arr1[i+1] = ed;
			occur[ed].pb(i+1);
		}
		fori(n)
			cin>>arr[i+1], --arr[i+1];
		ll st = 1;
		Segtree lz;
		lz.init(1, 1, n);
		Segtree::node query(1, n, inf, 0);
		lz.que(1, query);
		bool fc  = 0;
		while(st <= n){
	//		cout<<"st : "<<st<<endl;
			ll sv = st;
			while(st+1 <= n && arr[st+1] >= arr[st])
				++st;
			for(sv; sv<=st; ++sv){
				ll ed = arr[sv];
				if(!occur[ed].size()){
					fc = 1;
					break;
				}
	//			cout<<"occurence "<<occur[ed][0]<<endl;
				Segtree::node query(1, occur[ed][0], inf, 0);
				lz.que(1, query);
	//			cout<<"result "<<query.val<<endl;
				if(query.val != ed){
					fc = 1;
					break;
				}
				Segtree::node query1(occur[ed][0], occur[ed][0], 0, inf);
				lz.upd(1, query1);
				occur[ed].pop_front();
			}
			if(fc)
				break;
			
			++st;
		}
		if(fc)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}