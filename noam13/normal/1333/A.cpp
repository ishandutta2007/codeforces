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
const int INF = 1e18;

void solve(){
    int n,m; cin>>n>>m;
    vvb b(n, vb(m,0));
    loop(i,0,n){
        for(int j=i%2;j<m;j+=2) b[i][j] = 1;
    }
    if ((n*m)%2==0) {
        if (n%2) b[1][0] = 1;
        else b[0][1] = 1;
    }
    loop(i,0,n) {loop(j,0,m) cout<<(b[i][j]?'B':'W'); cout<<endl;}
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a

*/