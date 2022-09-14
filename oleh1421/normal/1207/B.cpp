#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[101][101];
int b[101][101];
int32_t main() {
    int n,m;cin>>n>>m;
    vector<pair<int,int> >ans;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                if (!b[i][j]){
                if (i==n || j==m){
                    cout<<-1;
                    return 0;
                }
                b[i][j]=1;
                b[i][j+1]=1;
                b[i+1][j]=1;
                b[i+1][j+1]=1;
                ans.push_back({i,j});
                } else if (a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]){
                b[i][j]=1;
                b[i][j+1]=1;
                b[i+1][j]=1;
                b[i+1][j+1]=1;
                ans.push_back({i,j});
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!=b[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<(int)ans.size()<<endl;
    for (auto i:ans) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}


///2007521364118