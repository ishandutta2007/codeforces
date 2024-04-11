#include <bits/stdc++.h>
#define int int64_t
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
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getp(int k, int n, int m){
    if (n<m) swap(n,m);
    if (k>=m) return k+m-1;
    return 2*k;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m,p; cin>>n>>m>>p;
    int l = max(n,m);
    vi a(n), b(m);
    loop(i,0,n) cin>>a[i];
    loop(i,0,m) cin>>b[i];
    int i = 0, j=0;
    for(;i<n;i++){
        if (a[i]%p) break;
    }
    for(;j<m;j++){
        if (b[j]%p) break;
    }
    cout<<i+j<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3 2 2
1 1 2
2 1
*/