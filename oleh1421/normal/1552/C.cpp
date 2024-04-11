//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
int x[N],y[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=k;i++) {
        cin>>x[i]>>y[i];
        if (x[i]>y[i]) swap(x[i],y[i]);
    }
    ll res=(n-k)*(n-k-1)/2;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            if (x[i]<x[j] && x[j]<y[i] && y[i]<y[j]) res++;
//            if (x[i]<x[j] && x[j]<y[i] && y[i]<y[j]) res++;
        }
    }
    for (int i=1;i<=k;i++){
        int cntA=y[i]-x[i]-1;
        int cntB=2*n-cntA-2;
        for (int j=1;j<=k;j++){
            if (i==j) continue;
            if (x[i]<x[j] && x[j]<y[i]) cntA--;
            else cntB--;
            if (x[i]<y[j] && y[j]<y[i]) cntA--;
            else cntB--;
        }
        res+=min(cntA,cntB);
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//5 10 5 9
/**
10 6
14 6
2 20
9 10
13 18
15 12
11 7
**/