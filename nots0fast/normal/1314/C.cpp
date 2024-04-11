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
#define MAX (int)(2*pow(10,3) + 100)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,18);
ll modulo = 998244353;
ld eps = 1e-6;



struct Segtree{			// !!! 1 based indexing !!!
	

	struct node{
		ll l , r, val, tagval;						 											
		bool tag;
		node(){}													
		node(ll l, ll r, ll val, ll tagval) : l(l), r(r), val(val), tagval(tagval), tag(0){}		
		void integrate(){	
			val+=tagval;
			if(val>= inf){
				val = inf;
			}
		}
		node operator+(node other){														
			return node(l, other.r, val + other.val ,0);									
		}
		void operator+=(node& other){						
			// merge other's "tagval" to our "tagval" only !!!! otherwise need modification
			tagval+=other.tagval;
			if(tagval >= inf){
				tagval = inf;
			}
		}
		void operator*=(node& other){	// TODO merge node value to query value
			// merge other's "val" to our "val" only !!!! otherwise need modification
			val += other.val;
			if(val >= inf){
				val = inf;
			}
		}
	};
	
	node* lazy = new node[MAX];	
	void init(ll num, ll l , ll r){
		if(l==r){
			lazy[num] = node ( l, r, 0, 0 );  
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

Segtree segs[MAX/2];




void deal(){
	ll n , m , k;
	cin>>n>>m>>k;
	vector<vector<ll> > num(n , vector<ll> (n,0));
	set<string> strings;
	string a;
	cin>>a;
	fori(n){
		string b = "";
		for(ll j = i; j<n; j++){
			b+=a[j];
			strings.insert(b);
		}
	}
	vector<string> all(strings.begin(), strings.end());
	fori(n){
		string b = "";
		for(ll j = i; j<n; j++){
			b+=a[j];
			num[i][j] = lower_bound(all.begin(), all.end(), b) - all.begin();
			num[i][j] = all.size()-1-num[i][j];
		}
	}
	reverse(all.begin(), all.end());
	
	ll lo = 0, hi = all.size()-1;
	while(lo< hi){
		ll mid = (lo+hi)/2;
		vector<vector<ll> > dp(n+1, vector<ll> (m+1, 0));
		dp[0][0] = 1;
		fori(n+1){
			if(i>1){
				forj(m+1){
					dp[i][j] += dp[i-1][j];
					if(dp[i][j] > k){
						dp[i][j] = k;
					}
				}
			}
			for(ll j = i+1; j<=n; j++){
				if(num[i][j-1] <= mid){
					for(ll x = 1; x<=m; x++){
						dp[j][x] += dp[i][x-1];
						if(dp[j][x] > k){
							dp[j][x] = k;
						}
					}
					break;
				}
			}
		}
/*		cout<<"we at "<<mid<<" "<<all[mid]<<endl;
		fori(n+1){
			forj(m+1){
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<"the answer at "<<mid<<" "<<all[mid]<<" is "<<dp[n][m]<<endl;
*/		
		if(dp[n][m] >= k){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout<<all[lo];
	
	
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}