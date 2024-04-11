// Thanks to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
//#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
//#define mod 1000000007
/*********VARIABLE****************/
typedef pair<int,int> ii;
/******************************/
const int MAX_MASK = 1<<18;
 
long long dp[MAX_MASK+ 1][20];
int a[20];
int mat[20][20];
/*********FUNCTIONS**************/
void init(int n){
	int i, j;
	for(i=0;i<=(1<<n);i++)
		for(j=0;j<n;j++)
			dp[i][j] = -1;
	//cout<<"ok\n";
}
 
int n;
 
void printB(int n, int k, int ans){
	int i;
	for(i=5;i>=0;i--)
		cout<<(n>>i & 1);
	cout<<" "<<k<<": "<<ans<<"\n";;
}
long long solve(int mask, int last) {
	//cout<<mask<<" "<<last<<"\n";
	assert(((1<<last) & mask) );
	
	if(dp[mask][last]!=-1) return dp[mask][last];
	long long i;
	long long  ans =0;
	for(i=0;i<n;i++){
		if(i==last) continue;
		if( (1<<i) & mask) {
			ans  = max(ans, mat[i][last]  + solve(mask&(~(1<<last)), i))  ;
		}
	}
	ans+=a[last];
	//printB(mask, last, ans);
	return dp[mask][last] = ans;
}
/***********MAIN**************/
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int  m, k, i;
	cin >> n >> m>> k;
	init(n);
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<k;i++) {
		int a, b, c;
		cin >> a>>b >> c;
		mat[a-1][b-1] = c;
	}
	
	long long ans = 0;
	for(i=0;i<(1<<n);i++) {
		for(int j=0;j<n;j++) {
			if( (( (1<<j) &i) >0 ) && __builtin_popcount(i)==m){
				// printB(i);
				// cout<<j<<": ";
				ans  = max(ans,  solve(i, j));
			}
		}
	}
	cout<<ans<<"\n";
}