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
const int INF = 4e18, MOD = 1e9+7;
const double eps = 1e-9;

void print(vii& p){
    cout<<p.size()<<endl;
    for(auto a:p) cout<<a.x<<" "<<a.y<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii p;
    /*if (n==1){
        loop(i,0,5) {
            p.pb({2,i});
            if (i!=2) p.pb({i,2});
        }
        p.pb({4,0}); p.pb({0,4});
        p.pb({3,0}); p.pb({0,3});
        p.pb({4,1}); p.pb({1,4});
        print(p);
        return 0;
    }*/
    p.pb({-1,0});
    p.pb({-2,0});
    p.pb({-2,1});
    p.pb({-2,2});
    p.pb({-1,2});
    loop(i,0,n){
        loop(j,-2,3)  {
            p.pb({2*i,j});
        }
        p.pb({2*i+1,0});
    }
    for(int i=0;i+1<n;i++){
        if (i%2) p.pb({2*i+1,2});
        else p.pb({2*i+1,-2});
    }
    if (n%2){
        p.pb({2*n,0});
        p.pb({2*n,-1});
        p.pb({2*n,-2});
        p.pb({2*n-1,-2});
    }
    else{
        p.pb({2*n,0});
        p.pb({2*n,1});
        p.pb({2*n,2});
        p.pb({2*n-1,2});
    }
    print(p);
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4

*/