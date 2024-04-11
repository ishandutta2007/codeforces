#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int a[200001];
int d[201][201];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==0){
            n--;
            i--;
        }
    }
    if (n>128){
        cout<<3;
        return 0;
    }
    int res=10001;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            d[i][j]=100001;
            if (i==j) d[i][i]=0;
            else if (a[i]&a[j]) d[i][j]=1;
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                if (i==k) continue;
                if (j==k) continue;
                //d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                if (a[i]&a[k] && a[j]&a[k]) res=min(res,d[i][j]+2);
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                //if (a[i]&a[k] && a[j]&a[k]) res=min(res,d[i][j]+2);
            }
        }
    }
    if (res>1000) cout<<-1;
    else cout<<res;
    return 0;
}