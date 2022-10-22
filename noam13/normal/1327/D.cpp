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


void solve(){
    int n; cin>>n;
    vi per(n); loop(i,0,n) cin>>per[i], per[i]--;
    vi c(n); loop(i,0,n) cin>>c[i], c[i]--;
    vb check(n,0);
    int ans=INF;
    loop(i,0,n){
        if (!check[i]){
            vi v;
            for(int cur=i; !check[cur];cur=per[cur]) v.pb(cur), check[cur]=1;
            int m = v.size();
            loop(step,1,m+1){
                if (m%step) continue;
                loop(s,0,step){
                    bool can=1;
                    for(int cur=s;cur+step<m;cur+=step) if(c[v[cur]]!=c[v[cur+step]]) can=0;
                    if (can){
                        chkmin(ans, step);
                        break;
                    }
                }
            }
        }   
    }
    cout<<ans<<endl;
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
g++ d.cpp -o a & a
3
4
1 3 4 2
1 2 2 3
5
2 3 4 5 1
1 2 3 4 5
8
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4

*/