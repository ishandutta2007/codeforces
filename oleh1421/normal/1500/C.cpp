//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1510;
int a[N][N];
int b[N][N];
int n,m;
int p[N];
int s[N][N];
vector<int>ans;
void rec(vector<pair<int,int> >V){
//    cout<<l<<" "<<r<<endl;
    bool eq=true;
    for (auto cur:V){
        int l=cur.first;
        int r=cur.second;
        for (int i=l;i<r;i++){
            eq&=(p[i]<p[i+1]);
        }
    }
    if (eq) return;
    vector<pair<int,int> >nV;
    for (int i=1;i<=m;i++){
        bool ok=true;
        bool eq=true;
        for (auto cur:V){
            if (s[i][cur.first]!=s[i][cur.second]) ok=false;
            if (b[cur.first][i]!=b[cur.second][i]) eq=false;
        }
        if (!ok || eq) continue;
//        cout<<i<<" "<<s[i][l]<<" "<<s[i][r]<<endl

        for (auto cur:V){
            int l=cur.first;
            int r=cur.second;
            int L=l;
            for (int j=l+1;j<=r;j++){
                if (b[j][i]!=b[j-1][i]){
                    if (L!=j-1) nV.push_back({L,j-1});
                    L=j;
                }
            }
            if (L!=r) nV.push_back({L,r});
        }
        rec(nV);
        ans.push_back(i);

        return;
    }
    cout<<-1<<endl;
    exit(0);
}
void solve(){
    cin>>n>>m;
    vector<pair<vector<int>,int> >A;
    for (int i=1;i<=n;i++){
        vector<int>v;
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            v.push_back(a[i][j]);
        }
//        sort(v.begin(),v.end());
        A.push_back({v,i});
    }
    sort(A.begin(),A.end());
    vector<pair<vector<int>,int> >B;
    for (int i=1;i<=n;i++){
        vector<int>v;
        for (int j=1;j<=m;j++){
            cin>>b[i][j];
            v.push_back(b[i][j]);
        }
//        sort(v.begin(),v.end());
        B.push_back({v,i});
    }
    sort(B.begin(),B.end());
    for (int i=0;i<n;i++){
        if (A[i].first!=B[i].first){
            cout<<-1<<endl;
            return;
        }
        p[B[i].second]=A[i].second;
    }
    for (int i=1;i<=m;i++){
        s[i][1]=0;
        for (int j=2;j<=n;j++){
            s[i][j]=(s[i][j-1]+(b[j][i]<b[j-1][i]));
        }
    }
//    cout<<p[1]<<" "<<p[2]<<endl;
    rec({{1,n}});
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 3

1 2 2
2 4 4
3 2 2
3 2 3
1 2 3

1 2 2
1 2 3
2 4 4
3 2 2
3 2 3

**/