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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD = 998244353;



int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi a(n), b(m);
    loop(i,0,n) cin>>a[i];
    loop(j,0,m) cin>>b[j];
    reverse(all(a));
    reverse(all(b));
    int i = 0, ans = 1;
    loop(j,0,m){
        int first = -1;
        while(i<n && a[i]>=b[j]){
            if (a[i]==b[j] && first==-1) first = i;
            i++;
        }
        if (first==-1) ans = 0;
        else {
            if (j==m-1) continue;
            ans = ans * (i-first) % MOD;
        }
    }
    if (i!=n) ans = 0;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a0.cpp -o a & a
6 3
12 10 20 20 25 30
10 20 30
*/