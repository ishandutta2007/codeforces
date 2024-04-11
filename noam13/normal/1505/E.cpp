#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<string> aa(n);
    loop(i,0,n) cin>>aa[i];
    loop(i,0,n) for(auto& c:aa[i]) c = (c=='*');
    int x = 0, y = 0;
    int ans = aa[0][0];
    while(1){
        ii best = {INF, -1};
        int a=-1,b;
        loop(i,x,n) loop(j,y,m){
            if (i==x && j==y) continue;
            if (!aa[i][j]) continue;
            ii d = {i-x+j-y, i-x};
            if (d<best){
                best = d;
                a = i, b = j;
            }
        }
        if (a==-1) break;
        ans ++;
        x = a, y = b;
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -D_GLIBCXX_DEBUG -o a & a
4 3
*..
.*.
..*
...



*/