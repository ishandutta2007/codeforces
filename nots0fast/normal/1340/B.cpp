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
#define MAX 2020
#define MAX2 2020
#define pb(a) push_back(a)
#define M 1010
#define N 100100
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
ll modulo = pow(10,9) + 7;
ld eps = 1e-9;
 
ifstream in;
ofstream out;
 
 
 
 
// #define cin in
// #define cout out

#define num 10
#define sz 7

vector<bitset<sz>> all({bitset<sz>("1110111"), bitset<sz>("0010010"), bitset<sz>("1011101"), bitset<sz>("1011011"), bitset<sz>("0111010"), bitset<sz>("1101011"), bitset<sz>("1101111"), bitset<sz>("1010010"), bitset<sz>("1111111"), bitset<sz>("1111011")});


void deal(){	
	ll n , k;
	cin>>n>>k;
	vector<string> arr(n);
	fori(n){
		cin>>arr[i];
	}
	
	vector<vector<ll> > wh(n+1, vector<ll>(k+1, -1));
	vector<vector<ll> > bg(n+1, vector<ll>(k+1, -1));
	wh[n][0] = 1;
	bg[n][0] = 1;
	for(ll i = n-1; i>-1; i--){
		bitset<sz> cur(arr[i]);
		forx((ll)all.size()){
			auto& el = all[x];
			if( (el | cur) == el ){
				ll cnt = (el ^ cur).count();
			//	cout<<"we made it nigga "<<el<<" "<<cnt<<endl;
				forj(k+1){
					if(wh[i+1][j] != -1 && j+cnt<=k){
						wh[i][j+cnt] = j;
						bg[i][j+cnt] = x;
					}
				}
			}
		}
	}
	
	if(bg[0][k] == -1){
		cout<<-1;
		return;
	}
	
	string acc = "";
	ll idx = 0, st = k;
	while(idx != n){
		acc+=to_string(bg[idx][st]);
		st = wh[idx][st];
		idx++;
	}
	
	cout<<acc;
	
}
 
int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}