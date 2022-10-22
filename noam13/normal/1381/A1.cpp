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
const int INF = 4e18;

int solve(){
    int n; cin>>n;
    string a, b; cin>>a>>b;
    vi ans;
    bool inv = 0;
    int l = 0, r = n-1;
    loop(i,0,n){
        int ni = n-i-1;
        if (!inv) {
            if (a[r]==b[ni]) {
                r--; continue;
            }
            if (a[l]==b[ni]) ans.pb(0);
            ans.pb(ni);
            l++;
        }
        else{
            if (a[l]!=b[ni]) {
                l++; continue;
            }
            if (a[r]!=b[ni]) ans.pb(0);
            ans.pb(ni);
            r--;
        }
        inv = !inv;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x+1<<" ";
    cout<<endl;
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
g++ a.cpp -o a & a
5
2
01
10
5
01011
11100
2
01
01
10
0110011011
1000110100
1
0
1

*/