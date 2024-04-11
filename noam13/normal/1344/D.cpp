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

inline int val(int a, int b){
    return a - 3*b*b - 3*b - 1;
}
int search(int a, int bound){
    if (bound >= a) return 0;
    int l = 0, r = a+1, mid, ans=-1;
    while(l<r){
        mid = (l+r)/2;
        if (val(a,mid)>bound) ans = mid, l = mid+1;
        else r = mid;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi cur(n), ans(n,0);
    int l = -INF, r = INF, b = -INF;
    while(l<r){
        int mid = (l+r);
        if (mid<0) mid--;
        mid/=2;
        int cnt = 0;
        loop(i,0,n) cur[i] = search(a[i], mid), cnt+=cur[i];
        if (cnt > k){
            l = mid + 1;
        }
        else{
            r = mid;
            b = mid;
        }
    }
    loop(i,0,n) ans[i] = search(a[i], b);
    loop(i,0,n) k-=ans[i];
    loop(i,0,n) if (k && val(a[i], ans[i]+1)==b) ans[i]++, k--;
    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
10 32
1 2 3 4 5 5 5 5 5 5

*/