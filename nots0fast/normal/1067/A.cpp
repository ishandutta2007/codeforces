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
#define MAX (int)(pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

ll arr[MAX];
int   dp[MAX][202][2]; // 1 has to be satisfied
int sums[MAX][202][2];

void deal(){
	ll n;
	cin>>n;
	fori(n)	
		cin>>arr[i+1], arr[i+1];
	forj(202)
		sums[0][j][0] = 1;
	for(int i=1; i<=n; i++){
		int st = arr[i];
		int nd = arr[i];
		if(arr[i] == -1){
			st = 1;
			nd = 200;
		}
		for(int j=st; j<=nd; j++){
			dp[i][j][1] = (sums[i-1][j-1][1] + sums[i-1][j-1][0]) % modulo;
			dp[i][j][0] = (sums[i-1][200][0] - sums[i-1][j-1][0]) % modulo;
			dp[i][j][0] = ( dp[i][j][0] + dp[i-1][j][1]) % modulo;
		}
		for(int j=1; j<=200; j++)
			fork(2)
				sums[i][j][k] = sums[i][j-1][k] + dp[i][j][k], sums[i][j][k] %= modulo;
	}
	cout<<(sums[n][200][0]  + modulo)%modulo;
	
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