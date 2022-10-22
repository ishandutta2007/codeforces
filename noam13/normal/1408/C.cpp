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
    int n,l; cin>>n>>l;
    vi a(n); loop(i,0,n) cin>>a[i];
    int i = 0, j = n-1;
    double pi = 0, pj = l;
    int v1 = 1, v2 = 1;
    double t = 0;
    while(i<=j){
        double t1 = (a[i]-pi)*1.0/v1, t2 = (pj - a[j])*1.0/v2;
        double d = min(t1, t2);
        pi+=v1*d, pj-=v2*d; t+=d;
        if (t1==d) i++, v1++;
        if (t2==d) j--, v2++;
    }
    //cout<<"T: "<<t<<" "<<pi<<" "<<pj<<endl;
    t+=(pj-pi)*1.0/(v1+v2);
    cout<<fixed<<setprecision(10)<<t<<endl;
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
5
2 10
1 9
1 10
1
5 7
1 2 3 4 6
2 1000000000
413470354 982876160
9 478
1 10 25 33 239 445 453 468 477

*/