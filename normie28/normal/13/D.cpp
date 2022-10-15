/*
khoi orz, go check out his algo
-normie-
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "robot.inp"
#define FILE_OUT "robot.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 1048576
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
const int N=500;
 
int XR[N], YR[N], XB[N], YB[N], arr[N][N];
 
bool ccw(int i, int j, int k) {
    int x1=XR[j]-XR[i],y1=YR[j]-YR[i],x2=XB[k]-XR[i], y2=YB[k]-YR[i];
    return 1LL*x1*y2-1LL*x2*y1>0;
}
 
int main() {
	fio;
    int n, m;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>XR[i]>>YR[i];
    for (int i=0; i<m; i++) cin>>XB[i]>>YB[i];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (XR[i]<XR[j]) {
        for (int k=0; k<m; k++) if (XB[k]>=XR[i] and XB[k]<XR[j] and ccw(i, j, k)) arr[i][j]++;
        arr[j][i]=-arr[i][j];
    }
    int res=0;
    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++) if (arr[i][j]+arr[j][k]+arr[k][i]==0) res++;
    cout<<res;
}