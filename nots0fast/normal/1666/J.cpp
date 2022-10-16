#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = pow(10, 9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;

ll gets(ll l1, ll r1, ll l2, ll r2, vector<vector<ll> >& pf){
	return pf[l2][r2] - pf[l1-1][r2] - pf[l2][r1-1] + pf[l1-1][r1-1];
}

void dfs(ll l, ll r, ll rt, vector<vector<ll> >& root, vector<ll>& par){
	if(r < l ){
		return;
	}
	ll cr = root[l][r];
	par[cr] = rt;
	dfs(l, cr-1, cr, root, par);
	dfs(cr+1, r , cr, root, par);
}

void deal(){
	ll n;
	cin>>n;
	vector<vector<ll> > arr(n+1, vector<ll>(n+1, 0));
	vector<vector<ll> > pf = arr;
	for(ll i = 1; i<=n; i++){
		for(ll j = 1; j<=n ; j++){
			ll ed;
			cin>>ed;
			arr[i][j] = ed;
			pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + ed;
		}
	}
	
	vector<vector<ll> > dp(n+2, vector<ll>(n+2, inf));
	vector<vector<ll> > root(n+2, vector<ll>(n+2, inf));
	// minimum sum of depth(i) * (sum from outside)
	fori(n+2){
		forj(n+2){
			if(i >= j){
				dp[i][j] = 0;
			}
			if(i == j){
				root[i][j] = i;
			}
		}
	}
	for(ll gap = 1; gap < n ; gap++){
		for(ll i = 1, j = gap+1; j<=n; i++, j++){
		//	cout<<endl<<endl<<endl<<"we are looking for "<<i<<" "<<j<<endl;
			for(ll k = i; k<=j; k++){
				ll s1 = gets(i, 1, k-1, n, pf) - gets(i, i, k-1, k-1, pf);
				ll s2 = gets(k+1, 1, j, n, pf) - gets(k+1, k+1, j, j, pf);
				
		//		cout<<"at point "<<k<<" s1 s2 is "<<s1<<" "<<s2<<endl;
				if(s1 + s2  + dp[i][k-1] + dp[k+1][j]< dp[i][j]){
					dp[i][j] = s1 + s2  + dp[i][k-1] + dp[k+1][j];
					root[i][j] = k;
		//			cout<<"so root for "<<i<<" "<<j<<" is "<<k<<endl;
				}
			}
		}
	}
	
//	cout<<"here "<<endl;
	vector<ll> par(n+1, 0);
	dfs(1, n, 0, root, par);
	
	for(ll i =1; i<=n; i++){
		cout<<par[i]<<' ';
	}
	
	
	
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}