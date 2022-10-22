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
    int n, m=1e7+10; cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    vi div(m,INF);
    for(int i=2;i*i<m;i++){
        if (div[i]!=INF) continue;
        for(int j=i*i;j<m;j+=i){
            chkmin(div[j],i);
        }
    }
    vii ans(n,{-1,-1});
    loop(i,0,n){
        if (div[a[i]]!=INF){
            int x = a[i], d = div[x];
            while(x%d==0) x/=d;
            if (x==1) continue;
            ans[i] = {d,x};
        }
    }
    loop(i,0,n) cout<<ans[i].x<<" "; cout<<endl;
    loop(i,0,n) cout<<ans[i].y<<" "; cout<<endl;
    return 0;
}
/*
color a
cls
g++ a0.cpp -o a & a
10
2 3 4 5 6 7 8 9 10 24

*/