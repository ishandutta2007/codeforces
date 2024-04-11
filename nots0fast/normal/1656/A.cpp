#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<pair<ll, ll> > arr;
		fori(n){
			ll ed;
			cin>>ed;
			arr.pb(mp(ed, i+1));
		}
		sort(arr.begin(), arr.end());
		cout<<arr[0].ss<<" "<<arr[n-1].ss<<'\n';
	}
}
	

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}