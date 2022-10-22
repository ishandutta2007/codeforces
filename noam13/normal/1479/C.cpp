#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int l,r; cin>>l>>r;
    int dif = r - (l-1);
    cout<<"YES"<<endl;
    if (l == r){
        cout<<"2 1"<<endl;
        cout<<"1 2 "<<l<<endl;
        return 0;
    }
    int n = 23;
    vvii g(n);
    vi p2(n);
    p2[0] = p2[1] = 1;
    loop(i,2,n) p2[i] = p2[i-1] * 2;
    vector<pair<ii, int>> e;
    loop(i,0,n-1){
        loop(j,i+1,n-1){
            e.pb({{i, j}, p2[i]});
        }
    }
    e.pb({{0, n-1},1});
    dif--;
    loopr(i,1,n-1){
        if (p2[i]<=dif){
            e.pb({{i, n-1}, dif-p2[i]+1});
            dif -= p2[i];
        }
    }
    if (l>1){
        e.pb({{n-1,n}, l-1});
        n++;
    }
    cout<<n<<" "<<e.size()<<endl;
    for(auto p:e) cout<<p.x.x+1<<" "<<p.x.y+1<<" "<<p.y<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4 6



*/