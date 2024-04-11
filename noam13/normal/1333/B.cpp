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

int solve(){
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi b(n); loop(i,0,n) cin>>b[i];
    vb plus(n+1), minus(n+1,0);
    loop(i,0,n) plus[i+1] = plus[i] + (a[i]==1);
    loop(i,0,n) minus[i+1] = minus[i] + (a[i]==-1);
    loop(i,0,n){
        if (a[i]==b[i]) continue;
        if (a[i]>b[i]) {
            if(!minus[i]) return cout<<"NO"<<endl,0;
        }
        else{
            if(!plus[i]) return cout<<"NO"<<endl,0;
        }
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
g++ b.cpp -o a & a
5
3
1 -1 0
1 1 -2
3
0 1 1
0 2 2
2
1 0
1 41
2
-1 0
-1 -41
5
0 1 -1 1 -1
1 1 -1 1 -1

*/