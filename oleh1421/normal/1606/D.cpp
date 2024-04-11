//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=998244353;
vector<int>a[N];
vector<int>L1[N],R1[N],L2[N],R2[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) {
        a[i].clear(),a[i].push_back(0);
        L1[i].clear();
        L1[i].resize(n+1,0);
        L2[i].clear();
        L2[i].resize(n+1,0);
        R1[i].clear();
        R1[i].resize(n+1,0);
        R2[i].clear();
        R2[i].resize(n+1,0);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x;cin>>x;
            a[j].push_back(x);
        }
    }
    vector<pair<int,int> >v;
    v.push_back({-1000000001,0});
    for (int i=1;i<=n;i++) v.push_back({a[1][i],i});
    sort(v.begin(),v.end());
    for (int i=1;i<=m;i++){
        R1[i][1]=a[i][v[1].second];
        if (i>1) {
            R1[i][1]=max(R1[i][1],R1[i-1][1]);
            for (int j=2;j<=n;j++){
                R1[i][j]=max({a[i][v[j].second],R1[i][j-1],R1[i-1][j]});
            }
        } else {
            for (int j=2;j<=n;j++){
                R1[i][j]=max(a[i][v[j].second],R1[i][j-1]);
            }
        }
        L1[i][n]=a[i][v[n].second];
        if (i>1) {
            L1[i][n]=min(L1[i][n],L1[i-1][n]);
            for (int j=n-1;j>=1;j--){
                L1[i][j]=min({a[i][v[j].second],L1[i][j+1],L1[i-1][j]});
            }
        } else {
            for (int j=n-1;j>=1;j--){
                L1[i][j]=min(a[i][v[j].second],L1[i][j+1]);
            }
        }
    }
    for (int i=m;i>=1;i--){
        R2[i][n]=a[i][v[n].second];
        if (i<m) {
            R2[i][n]=max(R2[i][n],R2[i+1][n]);
            for (int j=n-1;j>=1;j--){
                R2[i][j]=max({R2[i][j+1],R2[i+1][j],a[i][v[j].second]});
            }
        } else {
            for (int j=n-1;j>=1;j--){
                R2[i][j]=max({R2[i][j+1],a[i][v[j].second]});
            }
        }
        L2[i][1]=a[i][v[1].second];
        if (i<m){
            L2[i][1]=min(L2[i+1][1],L2[i][1]);
            for (int j=2;j<=n;j++){
                L2[i][j]=min({L2[i][j-1],L2[i+1][j],a[i][v[j].second]});
            }
        } else {
            for (int j=2;j<=n;j++){
                L2[i][j]=min({L2[i][j-1],a[i][v[j].second]});
            }
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if (R1[j][i]<L1[j][i+1] && R2[j+1][i+1]<L2[j+1][i]){
                string ans="";
                for (int t=0;t<n;t++) ans+="R";
                for (int t=1;t<=i;t++) ans[v[t].second-1]='B';
                cout<<"YES\n";
                cout<<ans<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<"NO\n";


}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
1
2 6
3 3 3 2 2 2
1 1 1 4 4 4
**/