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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int solve(){

    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vi a(n);
    int c = 0;
    loop(i,0,n) cin>>a[i], c+=a[i];
    loop(i,0,q){
        int op,x; cin>>op>>x;
        if (op==1){
            x--;
            c-=a[x];
            a[x] = 1-a[x];
            c+=a[x];
        }
        else{
            cout << (x<=c) << endl;
        }
    }
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
5 5
1 1 0 1 0
2 3
1 2
2 3
2 1
2 5


*/