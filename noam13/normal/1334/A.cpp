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
const int INF = 1e18, MOD = 1e9+7;

int solve(){
    int n; cin>>n;
    vi a(n), b(n);
    loop(i,0,n) cin>>a[i]>>b[i];
    loop(i,0,n) if(a[i]<b[i])  return cout<<"NO"<<endl,0;
    loop(i,0,n-1){
        int da = a[i+1]-a[i], db = b[i+1]-b[i];
        if (da<0 || db<0 || da<db) return cout<<"NO"<<endl,0;
    }
    cout<<"YES"<<endl;
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
6
3
0 0
1 1
1 2
2
1 0
1000 3
4
10 1
15 2
10 2
15 2
1
765 432
2
4 4
4 3
5
0 0
1 0
1 0
1 0
1 0


*/