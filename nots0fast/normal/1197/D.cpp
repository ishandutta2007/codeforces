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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7  ;
#define MAX (int)(pow(10,6)+ 10)


void deal(){
	ll n , k, m;
	cin>>n>>m>>k;
	vector<ll> arr(n+1), dp(n+1,0);
	fori(n)
		cin>>arr[i+1];
	for(ll i =1; i<=n; i++)
		dp[i] = dp[i-1] + arr[i];
	ll mn[m];  // min value for indices s.t. idx %m = i 
	fori(m)
		mn[i] = inf;
	ll mx  = 0;
	for(ll i =1; i<=n; i++){
		mn[i%m] = min(mn[i%m]+k, dp[i-1]+k);
		forj(m){
			if(j == (i%m))
				mx = max(mx, dp[i] - mn[j]);
			else
				mx = max(mx, dp[i] - mn[j]);
		}
	/*	cout<<"at index "<<i<<" the mins: ";
		forj(m){
			if(mn[j] == inf)
				cout<<1000<<' ';
			else	
				cout<<mn[j]<<' ';
		}
		cout<<endl;
		cout<<"the current max : "<<mx<<endl;
*/	} 
	cout<<mx;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/*

4 6
4 8 7 8
1 2 4
2 1 2 2
1 3 4
2 1 1 8
1 1 3
1 1 4

acacabbbbbbbacc

cccbbbaaa
*/