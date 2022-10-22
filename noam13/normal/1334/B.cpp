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
    int n,x; cin>>n>>x;
    vi a(n);
    loop(i,0,n) cin>>a[i], a[i]-=x;
    sort(all(a)); reverse(all(a));
    int car=0, cnt=0;
    loop(i,0,n){
        car+=a[i];
        if (car<0) break;
        cnt++;
    }
    cout<<cnt<<endl;
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
4
4 3
5 1 2 1
4 10
11 9 11 9
2 5
4 3
3 7
9 4 9

*/