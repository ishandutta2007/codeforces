//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=1010;
int a[N][N];
int n,m;
vector<pair<int,int> >st;
void upd(int i,int j){
    if (i<1 || i>=n || j<1 || j>=m) return;
    vector<int>v={a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1]};
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while (!v.empty() && !v.back()) v.pop_back();
    if (!v.empty() && v[0]==v.back()){
        st.push_back({i,j});
    }
}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            upd(i,j);
        }
    }
    vector<pair<int,pair<int,int> > >ans;
    while (!st.empty()){
        auto cur=st.back();

        int i=cur.first;
        int j=cur.second;
        st.pop_back();
        if (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==0) continue;
        int c=-1;
        if (a[i][j]) c=a[i][j];
        else if (a[i][j+1]) c=a[i][j+1];
        else if (a[i+1][j]) c=a[i+1][j];
        else c=a[i+1][j+1];
        ans.push_back({c,{i,j}});
        a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=0;
        for (int dx=-1;dx<=1;dx++){
            for (int dy=-1;dy<=1;dy++){
                upd(i+dx,j+dy);
            }
        }

    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                cout<<-1<<endl;
                return;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.second.first<<" "<<cur.second.second<<" "<<cur.first<<endl;

}

int32_t  main()
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
1
4 2
1 2
1 3
1 4
**/