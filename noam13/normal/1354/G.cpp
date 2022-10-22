#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
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
const int INF = 2e9;

int ask(int a, int b, int c, int d){
    cout<<"? "<<(b-a+1)<<" "<<(d-c+1)<<endl;
    loop(i,a,b+1) cout<<i+1<<" "; cout<<endl;
    loop(i,c,d+1) cout<<i+1<<" "; cout<<endl;
    /*int v; cin>>v;
    return v;*/
    string resp; cin>>resp;
    if (resp=="WASTED") exit(0);
    if (resp=="FIRST") return 1;
    if (resp=="SECOND") return -1;
    return 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int solve(){
    int n,kk; cin>>n>>kk;
    bool rock = 1;
    auto dist = uniform_int_distribution<int>(1, n-1);
    loop(j,0,28){
        int i = dist(rng);
        if (ask(0,0,i,i)<0) rock = 0;
    }
    if (!rock) return cout<<"! "<<1<<endl,0;
    int k = 1;
    for(;k*2<=n; k*=2){
        if (ask(0,k-1,k,2*k-1)){
            break;
        }
    }
    int l = k, r = min(n, 2*k), mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        if (ask(0, mid-l,l,mid)) ans = r = mid;
        else l = mid+1;
    }
    cout<<"! "<<ans+1<<endl;
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
g++ FindGift.cpp -o a & a
2
5 1
1 1 1 1 0




*/