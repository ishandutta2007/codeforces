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

int ask(int i){
    cout<<"? "<<i+1<<endl;
    cin>>i;
    return i;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int l = 0, r = n;
    while(l+1<r){
        int mid = (l+r-1)/2;
        if (ask(mid)>ask(mid+1)) l = mid + 1;
        else r = mid + 1;
    }
    if (l==n-1 || ask(l)<ask(l+1)) cout<<"! "<<l+1<<endl;
    else cout<<"! "<<l+2<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a


*/