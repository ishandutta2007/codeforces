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
const ll inf = pow(10, 9);
ll INF = 1e9;
ll modulo = 998244353;
ld eps = 1e-9;

void deal(){
	ll n;
	cin>>n;
	
	if(n == 2){
		cout<<-1;
		return;
	}
	
	
	ll k = (n%2);
	while((k+2)*(k+2) <= n){
		k+=2;
	}
	
	ll tot = k*k;
	
	ll cnt = 0;
	while(tot+2*k <= n){
		tot+=2*k;
		++cnt;
	}
	
	ll spec = n - tot;
	
	ll bt = 0;
	
	if(spec){
		bt = 1;
	}
	
	ll mn = cnt+k + bt;
	
	cout<<mn<<'\n';
	
	vector<vector<char> > arr(mn, vector<char>(mn, '.'));
	
	fori(spec/2){
		arr[0][i] = 'o';
		arr[mn-1-i][mn-1-0] = 'o';
	}
	
	
	for(ll i = bt; i<mn; i++){
		forj(k){
			arr[i][j] = 'o';
			arr[mn-1-j][mn-1-i] = 'o';
		}
	}
	
	
	fori(mn){
		forj(mn){
			cout<<arr[i][j];
		}	
		cout<<'\n';
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}