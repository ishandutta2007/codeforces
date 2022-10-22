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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

int gcd(int a, int b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a, a);
}
int n,k;
ii ans = {INF,-INF};
void solve(int a, int b){
    int c = b-a;
    if (c<0) c+=k;
    loop(i,0,n){
        int v = (n*k) / gcd(i*k+c,n*k);
        chkmin(ans.x, v);
        chkmax(ans.y, v);
    }
}
int32_t main(){
    cin>>n>>k;
    int a,b; cin>>a>>b;
    solve(a,b);
    solve(a,k-b);
    solve(k-a,b);
    solve(k-a,k-b);
    cout<<ans.x<<" "<<ans.y<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
2 3
1 1


. . . . . . . . . . . . . . 

*/