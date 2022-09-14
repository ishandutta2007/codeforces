//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;

void solve(int Case){
    int n,m;cin>>n>>m;
    vector<vector<int> >a(n,vector<int>(m,0));
    int x=0,y=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin>>a[i][j];
        vector<int>v;
        for (int j=0;j<m;j++) v.push_back(a[i][j]);
        sort(v.begin(),v.end());
        vector<int>u;
        for (int j=0;j<m;j++){
            if (v[j]!=a[i][j]) u.push_back(j);
        }
        if (!u.empty()){
            x=u[0];
            y=u[1];
        }
    }
    for (int i=0;i<n;i++){
        swap(a[i][x],a[i][y]);
    }
    for (int i=0;i<n;i++){
        if (!is_sorted(a[i].begin(),a[i].end())){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<x+1<<" "<<y+1<<endl;

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
9 10 0 8
0 1
1 2
2 3
3 4
1 4
4 5
7 5
6 7
0 6
7 8



**/