#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 1510
#define ch 51
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int arr[n];
	int dp[n][n];
	fori(n)
		cin>>arr[i], dp[i][i] = arr[i] ;
	for(int gap=1; gap<n; ++gap)
		for(int i=0,j=gap; j<n; i++,j++)
			dp[i][j] = dp[i+1][j] ^ dp[i][j-1];
	for(int gap=1; gap<n; ++gap)
		for(int i=0,j=gap; j<n; i++,j++){
			if(dp[i][j-1] > dp[i][j])	dp[i][j] = dp[i][j-1];
			if(dp[i+1][j] > dp[i][j]) 	dp[i][j] = dp[i+1][j];
		}
	int q;
	cin>>q;
	fori(q){
		int l,r;
		cin>>l>>r; --l, --r;
		cout<<dp[l][r]<<'\n';
	}
}
int main() {
//	while(1)
    deal();
}