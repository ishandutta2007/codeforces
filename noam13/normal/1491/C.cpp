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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int solve(){
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int ans = 0;
    vi alr(n+1);
    loop(i,0,n){
        // int amt = max(alr[i], a[i] - (n-i-1));
        ans += max(a[i]-alr[i]-1, 0LL);
        // cout <<" "<<a[i]<<" "<<alr[i]<<endl;
        loop(j,2,a[i]+1){
            if (i+j>=n) break;
            alr[i+j]++;
        }
        int amt = max(alr[i] - (a[i]-1), 0LL);
        alr[i+1]+=amt;
    }
    cout << ans << endl;
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
g++ c.cpp -o a & a
1
8
4 4 2 2 2 2 2 2


3
7
1 4 2 2 2 2 2
2
2 3
5
1 1 1 1 1


*/