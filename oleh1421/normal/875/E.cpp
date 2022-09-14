#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=200010;
const int L=20;
const ll mod=998244353;
int mn[N][L];
int mx[N][L];
bool dp[N];
int x[N];
int n;
int l[N];
int r[N];
bool ok(int d){
    if (abs(x[1]-x[0])>d) return false;
    for (int i=0;i<=n+1;i++){
        l[i]=i+1;
        for (int j=L-1;j>=0;j--){
            if (l[i]+(1<<j)-1<=n+1){
                if (x[i]-mn[l[i]][j]<=d && mx[l[i]][j]-x[i]<=d) l[i]+=(1<<j);
            }
        }
    }
    for (int i=1;i<=n+1;i++) dp[i]=false;
    int mx=l[0];
    for (int i=2;i<=n+1;i++){
        if (abs(x[i]-x[i-1])>d) continue;
        if (mx>=i) mx=max(mx,l[i-1]);

    }
    return (mx>=n+2);


}
void solve(){
    cin>>n>>x[0]>>x[1];
    for (int i=2;i<=n+1;i++) cin>>x[i];
    for (int i=0;i<=n+1;i++) mn[i][0]=mx[i][0]=x[i];
    for (int i=1;i<L;i++){
        for (int j=0;j+(1<<i)-1<=n+1;j++){
            mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
            mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
        }
    }

//    cout<<ok(2)<<endl;
    int L=0;
    int R=1000000001;
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) R=mid;
        else L=mid;
    }
    cout<<R<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
608
7 11 12 13 14 15 17 19


4
5 100
1 10
10 1
100 100
**/