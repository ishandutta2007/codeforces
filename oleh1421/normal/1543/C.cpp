//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ld eps=1e-8;
using namespace std;
mt19937 rnd(time(NULL));
const int Q=30000;
const int inf=1000000001;
const int N=50010;
map<vector<ld>,ld>dp;
ld F(ld c,ld m,ld p,ld v){
    vector<ld>cur={c,m,p};
    if (dp.find(cur)!=dp.end()) return dp[cur];
    ld res=1.0;
    if (c>=v){
        if (m>=eps) res+=c*F(c-v,m+v/2.0,p+v/2.0,v);
        else res+=c*F(c-v,0,p+v,v);
    } else if (c>=eps){
        if (m>=eps) res+=c*F(0.0,m+c/2.0,p+c/2.0,v);
        else res+=c*F(0.0,0.0,p+c,v);
    }

    if (m>=v){
        if (c>=eps) res+=m*F(c+v/2.0,m-v,p+v/2.0,v);
        else res+=m*F(0.0,m-v,p+v,v);
    } else if (m>=eps){
        if (c>=eps) res+=m*F(c+m/2.0,0.0,p+m/2.0,v);
        else res+=m*F(0.0,0.0,p+m,v);
    }
    return dp[cur]=res;
}
void solve(){
    ld c,m,p,v;cin>>c>>m>>p>>v;
    dp.clear();
    cout<<setprecision(10)<<fixed<<F(c,m,p,v)<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
6 8
1 4
1 5
2 4
2 5
2 3
2 6
1 7
2 7
**/
//4 4
//1 2
//2 4
//1 4
//2 3
// 2 2 2 2 3 4 3 5
//
// 00000
// 01000
// 00011
// 00000
// 00000

//4 3
//4 9
//4 9
//4 9
//1 2
//
//? 2 3 4
//? 1 3 4
//? 1 2 4
//? 1 2 3