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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;


ll arr1[MAX], arr2[MAX];


void deal(){
	ll n , m , ta, tb, k;
	cin>>n>>m>>ta>>tb>>k;
	fori(n)
		cin>>arr1[i];
	fori(m)
		cin>>arr2[i];
	if( k>= n || k>=m){
		cout<<-1;
		return;
	}
	ll ind  = m;
	ll mx  =0;
	forj(m)
		if(arr2[j] >= arr1[k] + ta){
			ind = j;
			break;
		}
	if(ind == m){
		cout<<-1;
		return;
	}
	mx = arr2[ind] + tb;
	for(ll i=k-1; i>-1; i--){
		ll ql = k-i;
		while(ind>-1 && arr2[ind] >= arr1[i] + ta)
			--ind;
		++ind;
		if(ind + ql >= m){
			cout<<-1;
			return;
		}
		mx = max(mx, arr2[ind+ql] + tb);
	}
	cout<<mx;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1