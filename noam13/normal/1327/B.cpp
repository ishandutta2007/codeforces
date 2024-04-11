#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;

int solve(){
    int n; cin>>n;
    vvi g(n);
    vb chk(n,0);
    vb chp(n,0);
    loop(i,0,n){
        int k; cin>>k;
        loop(j,0,k){
            int x; cin>>x; x--;
            g[i].pb(x);
        }
        loop(j,0,k){
            if (!chk[g[i][j]]){
                chp[i] = chk[g[i][j]] = 1;
                break;
            }
        }
    }
    int k=-1, p=-1;
    loop(i,0,n){
        if (!chk[i]) k=i;
        if (!chp[i]) p=i;
    }
    if (k==-1 || p==-1) return cout<<"OPTIMAL"<<endl,0;
    cout<<"IMPROVE"<<endl<<p+1<<" "<<k+1<<endl;
    return 0;
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
g++ b.cpp -o a & a
5
4
2 2 3
2 1 2
2 3 4
1 3
2
0
0
3
3 1 2 3
3 1 2 3
3 1 2 3
1
1 1
4
1 1
1 2
1 3
1 4


*/