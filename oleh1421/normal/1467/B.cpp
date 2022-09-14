//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=305010;
const ll mod=1000000007;
int a[N];
int ok[N];
int n;
int F(int i){
    if (i<=1 || i>=n) return 0;
    if (a[i]>max(a[i-1],a[i+1]) || a[i]<min(a[i-1],a[i+1])) return 1;
    return 0;
}
void solve(){
    cin>>n;
    for (int i=0;i<=n+10;i++) ok[i]=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=2){
        cout<<0<<endl;
        return;
    }
    int bad=0;
    for (int i=2;i<n;i++){
         if (F(i)) bad++;
    }
    int res=bad;

    for (int i=1;i<=n;i++){
        int last=a[i];
        if (i>1){
            int cur=bad;
            for (int j=i-1;j<=i+1;j++) cur-=F(j);
            a[i]=a[i-1];
            for (int j=i-1;j<=i+1;j++) cur+=F(j);
            res=min(res,cur);
            a[i]=last;
        }
        if (i<n){
            int cur=bad;
            for (int j=i-1;j<=i+1;j++) cur-=F(j);
            a[i]=a[i+1];
            for (int j=i-1;j<=i+1;j++) cur+=F(j);
            res=min(res,cur);
            a[i]=last;
        }
    }
    cout<<res<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1
5
2 2 2 2 2
*/