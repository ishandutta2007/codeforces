#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 998244353;

string s,t;
int n,m;
bool good(int i, int j){
	if (j>=m) return 1;
	return s[i]==t[j];
}
void add(int &a, int b){
	a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>s>>t;
    n = s.size(), m = t.size();
    vvi dp(n+1, vi(n+1,0));
    loop(i,0,n) if(good(0,i)) dp[i][i] = 2;
    loop(k,1,n){
    	loop(i,0,n-k){
    		int j = i + k;
    		if (good(k,i)) add(dp[i][j], dp[i+1][j]);
    		if (good(k,j)) add(dp[i][j], dp[i][j-1]);
    	}
    }
    int ans = 0;
    loop(i,m-1,n) add(ans, dp[0][i]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a


*/