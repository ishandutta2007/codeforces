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
const int INF = 2e18, MOD = 1e9+7;

inline int sq(int x){
	return x*x;
}
inline int getv(int a, int b, int c){
	return sq(a-b)+sq(b-c)+sq(c-a);
}
int solve(){
    vi n(3); loop(i,0,3) cin>>n[i];
    vvi a(3); 
    loop(i,0,3){
    	a[i].resize(n[i]);
    	loop(j,0,n[i]) cin>>a[i][j];
    	sort(all(a[i]));
    }
    vi ind(3,0);
    int best = INF;
    bool end = 0;
    while(1){
    	chkmin(best, getv(a[0][ind[0]],a[1][ind[1]],a[2][ind[2]]));
    	ii mini = {INF,-1};
    	loop(i,0,3){
    		if (ind[i]+1>=n[i]) continue;
    		ind[i]++;
    		ii cur = {getv(a[0][ind[0]],a[1][ind[1]],a[2][ind[2]]),i};
    		ind[i]--;
    		mini = min(mini, cur);
    	}
    	if (mini.y==-1) break;
    	ind[mini.y]++;
    }
    cout<<best<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a


*/