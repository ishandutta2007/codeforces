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
#define ll int
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,7) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;

void check(vector<vector<char> >& arr, vector<vector<ll> >& dp, vector<vector<ll> >& dp1,  vector<ll>& row_sum, vector<ll>& col_sum){
	ll n = dp.size() - 1;
	ll m = dp[0].size() - 1;
	dp[1][1] = 1;
	for(ll i = 1; i<=n ;i ++)
		for(ll j = 1; j<=m; j++){
			if(i == 1 && j == 1)
				continue;
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			if(dp[i][j] > 10)
				dp[i][j] = 10;
			if(arr[i][j] == '#')
				dp[i][j] = 0;
		}
	dp1[n][m] = 1;
	for(ll i = n; i; i--)
		for(ll j = m; j; j--){
			if(j == m && i == n)
				continue;
			dp1[i][j] = dp1[i+1][j] + dp1[i][j+1];
			if(dp1[i][j] > 10)
				dp1[i][j] = 10;
			if(arr[i][j] == '#')
				dp1[i][j] = 0;
		}
	for(ll i =1; i<=n ; i++){
		row_sum[i] = m+1;
		for(ll j = m;  j ;j--){
			if(dp[i][j] == 0 || dp1[i][j] == 0)
				row_sum[i]= j;
			else
				break;
		}
	}
	for(ll j =1; j<=m; j++){
		col_sum[j] = n+1;
		for(ll i = n; i; i--){
			if(dp[i][j] == 0 || dp1[i][j] == 0)
				col_sum[j] = i;
			else
				break;
		}
	}
}


void deal(){
	ll n , m;
	cin>>n>>m;
	vector<vector<char> > arr(n+1, vector<char>(m+1));
	vector<vector<ll> > dp(n+1, vector<ll>(m+1, 0));
	vector<vector<ll> > dp1(n+2, vector<ll>(m+2, 0));
	vector<ll> row_sum(n+1, 0);
	vector<ll> col_sum(m+1, 0);
	fori(n)
		forj(m)
			cin>>arr[i+1][j+1];
//	cout<<"before "<<endl;
	check(arr, dp, dp1, row_sum, col_sum);
//	cout<<"after "<<endl;
	if(dp[n][m] == 0){
		cout<<0;
		return;
	}
		for(ll i = 1; i<=n; i++){
			for(ll j = 1; j<=m; j++){
				if( i == 1 && j == 1)
					continue;
				if( i == n && j == m)
					continue;
				bool gg = 1;
				if(i != 1)
					gg &= (row_sum[i-1] <= j+1);
				if(j!=1)
					gg &= (col_sum[j-1] <= i+1);
				if(gg){
			//		cout<<" gg at "<<i<<" "<<j<<endl;
					cout<<1;
					return;
				}
			}
		}
		cout<<2;
}

int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}

/*
5 5
.....
.....
...##
.....
..#..
*/