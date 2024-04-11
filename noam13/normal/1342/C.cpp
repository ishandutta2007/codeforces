#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

int solve(){
    int a,b,q; cin>>a>>b>>q;
    int n = a*b;
    vb prec(n,0);
    int cnt = 0;
    loop(i,0,n){
        int dif = ((i%a)%b) - ((i%b)%a);
        if (dif!=0) prec[i] = 1, cnt++;
    }
    vi pref(n+1,0);
    loop(i,0,n) pref[i+1] = pref[i] + prec[i];
    loop(i,0,q){
        int l,r; cin>>l>>r;
        int nl = l/n, nr = r/n;
        int ans = cnt * (nr - nl);
        l = l%n;
        r = r%n;
        ans = ans - pref[l] + pref[r+1];
        cout<<ans<<" ";
    }
    cout<<endl;
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
g++ c.cpp -o a & a
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200


*/