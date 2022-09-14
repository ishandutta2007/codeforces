//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
void solve(){
        int n;cin>>n;
        string s;cin>>s;
        string a="";
        string b="";
        vector<vector<int> >g(10);

        for (int i=0;i<n;i++) {
            g[s[i]-'0'].push_back(i);
        }
        int R=-1;
        vector<int>color(n,2);
        for (int i=0;i<=9;i++){
            if (g[i].empty()) continue;
            if (g[i][0]>R){
                for (auto to:g[i]) color[to]=1;
                R=g[i].back();
            } else {
                for (auto to:g[i]){
                    if (to>R) color[to]=1;
                }
                break;
            }
        }
        string t="";
        for (int i=0;i<n;i++){
            if (color[i]==1) t+=s[i];
        }
        for (int i=0;i<n;i++){
            if (color[i]==2) t+=s[i];
        }
        sort(s.begin(),s.end());
        if (t==s) for (int i:color) cout<<i;
        else cout<<'-';
        cout<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
         solve();
    }
    return 0;
}