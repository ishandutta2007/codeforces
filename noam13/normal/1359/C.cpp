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
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;
const double eps = 1e-9;

int solve(){
    int h,c,t; cin>>h>>c>>t;
    if (c+h>=2*t) return cout<<2<<endl,0;
    if (t>=h) return cout<<1<<endl,0;
    int x = int((h-t) / (2.0*t-h-c)+eps);
    double a1 = (x*c + (x+1)*h)*1.0/(2*x+1);
    x++;
    double a2 = (x*c + (x+1)*h)*1.0/(2*x+1);
    x--;
    x = 2*x+1;
    bool b = 0;
    if (abs(a1-t) > abs(a2-t)) swap(a1,a2), b = 1;
    if (abs(h-t)<abs(a1-t)) cout<<1<<endl;
    else cout<<(x + b*2)<<endl;
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
3
30 10 20
41 15 30
18 13 18



*/