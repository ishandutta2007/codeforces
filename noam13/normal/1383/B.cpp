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
    vi a(n); loop(i,0,n) cin>>a[i];
    int m = 31;
    vi cnt(m);
    loop(i,0,n){
        loop(j,0,m) if(a[i]&(1<<j)) cnt[j]++;
    }
    loopr(j,0,m){
        //cout<<cnt[j]<<endl;
        if (cnt[j]%2){
            if (cnt[j]%4==1) return cout<<"WIN"<<endl,0;
            else{
                if ((n-cnt[j])%2) return cout<<"WIN"<<endl,0;
                else return cout<<"LOSE"<<endl,0;
            }
        }
    }
    cout<<"DRAW"<<endl;
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
g++ b.cpp -o a & a
3
3
1 2 2
3
2 2 3
5
0 0 0 2 2

*/