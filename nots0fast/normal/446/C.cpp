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
#define MAX 1<<20
#define MAX2 300300
#define pb(a) push_back(a)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 9;

// matrix structure for classic Matrix exponentiation type of problems


struct Matrix{ // !!! everything is an integer , and we take modulo while exponentiating (is available up to 2^30) / multiplying 
			   // n should be nonzero
	vector<vector<ll> > arr;
	int n, m;
	Matrix(){}
	Matrix(int n, int m, bool id){			// if id is true (it must be a square matrix!!) identity matrix is created
		this->n = n , this->m = m;
		arr.resize(n, vector<ll> (m, 0));
		if(id)
			fori(n)
				arr[i][i] = 1;
	}
	Matrix(vector<vector<ll> > arr){
		this->arr = arr;
		n = arr.size();
		m = arr[0].size();
	}
	Matrix Multiply(Matrix& A){
		int n1 = A.n , m1 = A.m;
		assert(m==n1);
		vector<vector<ll> > lz;
		lz.resize(n); 
		fori(n){
			lz[i].resize(m1);
			forj(m1)	lz[i][j] = 0;
		}
		fori(n)
			for(int j1=0; j1<m1; j1++)
				for(int i1=0; i1 <n1; i1++)
					lz[i][j1]+=arr[i][i1]*A.arr[i1][j1], lz[i][j1]%=modulo;
		return Matrix(lz);
	}
};
Matrix 	all[MAX2];
ll	  	arr[MAX2];
void pre(){
	vector<vector<ll> > fib( 3, vector<ll> (3, 0) );
	fib[0][0] = 1 , fib[1][0] = 1, fib[0][1] =1 , fib[0][2] = 1, fib[1][2] = 1, fib[2][2] = 1;
	Matrix fiba(fib);
	all[0] = Matrix(3,3,1);
	for(int i=1; i<MAX2; i++)
		all[i] = all[i-1].Multiply(fiba);
}
ll calc(ll& fibn , ll& fibn_, ll& val, int ind){
	val += fibn*all[ind].arr[0][2] + fibn_*all[ind].arr[1][2] + fibn*all[ind].arr[2][2] ;
	val %= modulo;
}
void calc1( ll& fibn, ll& fibn_, ll& tag1, ll& tag2 , int ind){
	tag1 += fibn*all[ind].arr[0][0] + fibn_*all[ind].arr[1][0], tag1 %= modulo;
	tag2 += fibn*all[ind].arr[0][1] + fibn_*all[ind].arr[1][1], tag2 %= modulo;
}
struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval, tagval_;						 											// TOD add new types if needed
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval, ll tagval_) : tagval_(tagval_), l(l), r(r), val(val), tagval(tagval), tag(0){}	// TOD initialize new types as well 	
		void integrate(){								   										// TOD for merging tag value to node value
			calc( tagval, tagval_, val, r-l);
		}
		node operator+(node other){																// TOO for merging 2 node values (children to parent) !!!order matters!!!
			return node(l, other.r, (val+other.val)%modulo,0, 0);									
		}
		void operator+=(node& other){															// TOO for merging 2 tag values 
			calc1(other.tagval, other.tagval_, tagval, tagval_, l-other.l);
		}
		void operator*=(node& other){															// TOD for queries (merging a segtree node to a query)
			val += other.val;
			val%=modulo;
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			//TOD	 lazy[num] = node ( proper initial values ) 
			lazy[num] = node( l, l, arr[l], 0, 0);
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
		lazy[num].tagval = 0, lazy[num].tagval_ = 0;
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
void display(Matrix& A){
	cout<<"number of rows "<<A.n<<" number of columns "<<A.m<<endl;
	fori(A.n){
		forj(A.m)
			cout<<A.arr[i][j]<<' ';
		cout<<'\n';
	}
}
#define Max_pow 63
Matrix exponentiate(Matrix& B, ll pv){
	Matrix start( B.n, B.n, 1);
	for(ll i = 62; i>-1; i--){
		start = start.Multiply(start);
		if(((ll)1<<i) & pv)
			start = start.Multiply(B);
	}
	return start;
}
void deal(){
	pre();
	int n, m;
	cin>>n>>m;
	fori(n)
		cin>>arr[i+1];
	// u ll have to modify "node" struct accordingly
	// usage : 
	// Segtree lz
	// lz.init(1,1,n);
	// Segtree::node query( you probably want the update range l,r here , no base value, a tagvalue of the update ), 	    lz.upd( 1, query );
	// Segtree::node query(  you probably want the query range l,r here, a base value, no tag value ),						lz.que(1, query ), 	cout<<query.val;
	Segtree lz;
	lz.init(1,1,n);
	fori(m){
		int ty;
		cin>>ty;
		if(ty == 1){
			int l, r;
			cin>>l>>r;
			Segtree::node query(l, r, 0, 1, 0);
			lz.upd(1, query);
		}
		else{
			int l, r;
			cin>>l>>r;
			Segtree::node query(l, r, 0, 1, 0);
			lz.que(1, query);
			cout<<query.val<<'\n';
		}
	}
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}