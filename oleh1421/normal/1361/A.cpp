//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500501;
vector<int>g[N];
int t[N];
int val[N];
vector<int>p[N];
int mex(vector<int>v){
    sort(v.begin(),v.end());


    if (v.empty() || v[0]>1) return 1;
    for (int i=1;i<v.size();i++){
        if (v[i]>v[i-1]+1) return v[i-1]+1;
    }
    return v.back()+1;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        cin>>t[i];
        p[t[i]].push_back(i);
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        for (auto x:p[i]){
            v.push_back(x);
        }
    }
    for (auto x:v){
        vector<int>cur;
        for (auto to:g[x]){
            if (val[to]) cur.push_back(val[to]);
        }
        val[x]=mex(cur);
    }
//    for (auto i:v) cout<<i<<" ";
//    cout<<endl;

    for (int i=1;i<=n;i++){
        if (t[i]!=val[i]){
            cout<<"-1\n";
            return;
        }
    }
    for (auto i:v) cout<<i<<" ";
    cout<<endl;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*

*/