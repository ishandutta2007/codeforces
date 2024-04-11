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

int dp[51][51][2][210];
int C[51][51];
int k;
int f(int x1,int y1,int x2,int y2,bool p,int m){
	if(m==0)return !x1 and !y1 and p;
	int &ans = dp[x1][y1][p][m];
	if(ans!=-1)return ans;ans=0;
	if(!p){
		FOR(i,0,x1)
		FOR(j,0,y1){
			int w = i+2*j;
			if(w==0)continue;
			if(w>k)continue;
			int yo = mul(C[x1][i],C[y1][j]);
			ans=add(ans,mul(yo,f(x1-i,y1-j,x2+i,y2+j,!p,m-1)));
		}
	}
	else{
		FOR(i,0,x2)
		FOR(j,0,y2){
			int w = i+2*j;
			if(w==0)continue;
			if(w>k)continue;
			int yo = mul(C[x2][i],C[y2][j]);
			ans=add(ans,mul(yo,f(x1+i,y1+j,x2-i,y2-j,!p,m-1)));
		}
	}
	return ans;
}

int main()
{
    boost;
    memset(dp,~0,sizeof dp);
    FOR(i,0,50)C[i][0]=1;
    FOR(i,1,50)FOR(j,1,i)C[i][j]=add(C[i-1][j],C[i-1][j-1]);
    
    int n;cin>>n>>k;k/=50;
    int a=0,b=0;
    FOR(i,1,n){int x;cin>>x;x==50?a++:b++;}
    
    int ans=0;
    FOR(i,1,205){
    	ans=f(a,b,0,0,0,i);
    	if(ans){cout<<i<<"\n"<<ans;return 0;}
    }
    cout<<"-1\n0";
	return 0;
}