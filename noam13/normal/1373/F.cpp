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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int MOD = 998244353;


int solve(){
    int n; cin>>n;
    vi a(n), b(n);
    int sa=0, sb=0;
    loop(i,0,n) cin>>a[i], sa+=a[i];
    loop(i,0,n) cin>>b[i], sb+=b[i];
    if (sb<sa) return cout<<"NO"<<endl,0;
    int cur = -b[0], mini = 0;
    loop(i,1,2*n){
        int ind = i%n;
        cur += a[ind] - b[ind];
        //cout<<"CUR: "<<cur<<endl;
        if (cur - mini > 0) return cout<<"NO"<<endl,0;
        chkmin(mini, cur + b[ind]);
    }
    cout<<"YES"<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
5
3
2 3 4
3 3 3
3
3 3 3
2 3 4
4
2 3 4 5
3 7 2 2
4
4 5 2 3
2 3 2 7
2
1 1
10 10


*/