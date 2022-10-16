#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")

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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 6);
ll modulo = pow(10,9) + 7;

void deal(){
	ll n;
	cin>>n;
	ll lz = 1;
	for(ll i = 1; i<=n; i++){
		cout<<"? ";
		forj(n-1){
			cout<<n<<' ';
		}
		cout<<i<<endl;
		ll ans;
		cin>>ans;
		if(ans != 0){
			lz = n+1-i;
			break;
		}
	}
	vector<ll> arr(n+1, -1);
	arr[n] = lz;
	for(ll i = 1; i<=n; i++){
		if(i == lz){
			continue;
		}
		ll ad1 = max(lz, i)+1-i, ad2 = max(lz, i) + 1 - lz;
		cout<<"? ";
		forj(n-1){
			cout<<ad1<<' ';
		}
		cout<<ad2<<endl;
		ll ans;
		cin>>ans;
		arr[ans] = i;
	}
	cout<<"! ";
	for(ll i = 1; i<=n; i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}