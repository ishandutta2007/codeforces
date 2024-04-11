/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/


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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 998244353;
double eps = 1e-6;
ifstream in;
ofstream out;

#define MAX 200'200

ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}

ll fkt[MAX];
ll inv[MAX];

void pre(){
	fkt[0] = 1;
	for(ll i = 1;  i<MAX; i++){
		fkt[i] = fkt[i-1] * i % modulo;
	}
	inv[MAX-1] = pow_mod(fkt[MAX-1], modulo-2);
	for(ll i = MAX-2; i>=0; i--){
		inv[i] = (inv[i+1] * (i+1)) % modulo;
	}
}

void updTillEnd(ll id, ll vl, vector<ll>& fen){
	ll sz = fen.size();
	while(id < sz){
		fen[id] += vl;
		if(fen[id] >= modulo){
			fen[id] -= modulo;
		}
		id += id & -id;
	}
}

ll queTillStart(ll id, vector<ll>& fen){
	ll s = 0;
	ll sz = fen.size();
	id = min(id, sz);
	while(id){
		s += fen[id];
		id -= id & -id;
	}
	return s % modulo;
}

ll brute(vector<ll>&  a, vector<ll>& b){
	sort(a.begin(), a.end());
	ll n = a.size(), m = b.size();
	ll tot = 0;
	do{
		ll less = 0;
		fori(min(n, m)){
			if(a[i] < b[i]){
				less = 1;
				break;
			}
			if(a[i] > b[i]){
				less = 2;
				break;
			}
		}
		if(!less){
			if(n < m){
				less = 1;
			}
			else{
				less = 2;
			}
		}
		if(less == 1){
			++tot;
		}
	}while(next_permutation(a.begin(), a.end()));
	return tot;
}

bool debug = 0;

void deal(){
	srand(time(NULL));
	pre();
	
	ll n, m;
	
	if(debug){
		n = rand() % 8 + 1, m = rand () % 8 + 1;
	}
	else{
		cin>>n>>m;
	}
	
	vector<ll> arrA(n);
	
	vector<ll> fenc(MAX, 0); // fencount and fensum
	fori(n){
		ll ed;
		if(debug){
			ed = rand() % 3 + 1;
			arrA[i] = ed;
		}
		else{
			cin>>ed;
		}
		updTillEnd(ed, 1, fenc);
	}
	
	
	vector<ll> arr(m);
	fori(m){
		if(debug){
			arr[i] = rand()% 3 + 1;
		}
		else{
			cin>>arr[i];
		}
	}
	
	ll mlt = fkt[n];
	// the multiplying factor , e.g. : k! / count1 !  count2 !  ... 
	
	
	for(ll i = 1; i<MAX; i++){
		ll cnt = queTillStart(i, fenc) - queTillStart(i-1, fenc);
		mlt *= inv[cnt];
		mlt %= modulo;
	}
	
	
//	cout<<"mlt is "<<mlt<<endl;
	
	
	ll ans = 0;
	fori(min(n, m) ){
		// how does mlt change
		// divide by (n-i) =  multiply by (n-i-1)! , divide by inverse (n-i)!
		mlt *= fkt[n-i-1];
		mlt %= modulo;
		mlt *= inv[n-i];
		mlt %= modulo;
		
		
		
		ll vl = arr[i];
		ll cr = queTillStart(vl-1, fenc);
		ans += cr * mlt % modulo;
		
	//	cout<<"cr is "<<cr<<" mlt is "<<mlt<<endl;
		
		
		ans %= modulo;
		
		ll cnt = queTillStart(vl, fenc) - queTillStart(vl-1, fenc);
		
		updTillEnd(vl, (modulo-cnt) % modulo, fenc);
		
		updTillEnd(vl, cnt-1, fenc);
		
		// multiply by cnt;
		mlt *= cnt;
		mlt %= modulo;
	}
	
	if(n < m){
		ans += mlt;
		ans %= modulo;
	}
	if(debug){
		assert(ans == brute(arrA, arr));
	}
	cout<<ans;
}

 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}