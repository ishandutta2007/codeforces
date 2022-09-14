//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=300010;
int a[N];
int n;
vector<int>g[N];
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];

//    random_shuffle(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;++j){
            if (a[j]>a[i]) g[i].push_back(j);
        }
    }
    vector<pair<int,int> >ans;
    for (int i=n;i>=1;i--){
        vector<pair<int,int> >v;
        for (int j=0;j<g[i].size();j++){
            v.push_back({a[g[i][j]],j});
        }
        sort(v.begin(),v.end());
        for (auto cur:v){
            ans.push_back({g[i][cur.second],i});
        }

    }
    for (auto cur:ans) swap(a[cur.first],a[cur.second]);
//    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;

}
int main()
{
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
1
9
2 0 1 1 2 4 4 2 0
*/