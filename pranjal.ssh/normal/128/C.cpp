#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}


int C[1001][1001];
inline int CC(int n,int k){
	if(n<0)return 0;
	if(k<=n)return C[n][k];
	return 0;
}
int main()
{
    boost;
   	FOR(i,0,1000)C[i][0]=1;
   	FOR(i,1,1000)
   		FOR(j,1,i)
   		C[i][j]=add(C[i-1][j-1],C[i-1][j]);
   	int n,m,k;cin>>n>>m>>k;
   	cout<<mul(CC(n-1,2*k),CC(m-1,2*k))<<"\n";
	return 0;
}