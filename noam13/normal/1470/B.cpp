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
const int MAX = 1e6 + 10;

vi divv;
int solve(){
    int n; cin>>n;
    map<vi, int> cnt;
    loop(i,0,n){
        int a; cin>>a;
        vi divs;
        while(divv[a]>1){
            divs.pb(divv[a]), a/=divv[a];
        }
        if (a>1) divs.pb(a);
        sort(all(divs));
        vi v;
        for(int d:divs){
            if (v.size() && v.back()==d) v.pop_back();
            else v.pb(d);
        }
        cnt[v]++;
    }
    int ans0 = 0, ans1 = 0;
    vi v;
    for(auto p:cnt){
        chkmax(ans0, p.y);
        if (p.y%2==0 || p.x.size()==0) ans1+=p.y;
    }
    chkmax(ans1, ans0);
    int q; cin>>q;
    loop(i,0,q){
        int t; cin>>t;
        if (t==0) cout<<ans0<<endl;
        else cout<<ans1<<endl;
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    divv.resize(MAX, 1);
    loop(x,2,MAX){
        if (divv[x]!=1) continue;
        for(int j = 2*x; j<MAX; j+=x) divv[j] = x;
    }
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
2
4
6 8 4 2
1
0
6
12 3 20 5 80 1
1
1

*/