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
#define MAX (int)(2*pow(10,5)+10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
const char nl = '\n';
ll modulo = pow(10,9)+7;

int arr[MAX];

void deal(){
	int n;
	cin>>n;
	fori(n){
		cin>>arr[i];
		if(arr[i] < 0)
			arr[i] = -arr[i];
	}
	sort(arr, arr+n);
	ll rg = 0;
	ll s = 0;
	fori(n){
		while(rg<n && arr[rg] <= arr[i]*2 )
			++rg;
		s+=(rg-i-1);
	}
	cout<<s<<endl;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}