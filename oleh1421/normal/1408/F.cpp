#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;

vector<pair<int,int> >ans;
void dv(vector<int>v){
    int n=v.size();
    for (int bt=1;bt<n;bt*=2){
        for (int i=0;i<n;i++){
            if (i&bt){
                ans.push_back({v[i^bt],v[i]});
            }
        }
    }
}
void solve(){
    int n;cin>>n;
    int tot=0;
    vector<int>bt;
    for (int i=0;i<20;++i){
        if (n&(1<<i)){
            bt.push_back(i);
            vector<int>v;
            for (int j=0;j<(1<<i);j++){
                v.push_back(tot++);
            }
            dv(v);
        }
    }
    tot=0;
    int R=n;
    vector<int>cur;
    for (int j=0;j<(1<<bt[0]);j++) cur.push_back(tot++);
    for (int i=1;i+1<bt.size();i++){
        while (cur.size()<(1<<bt[i])){
            int sz=cur.size();
            for (int j=0;j<sz;j++){
                ans.push_back({cur[j],--R});
                cur.push_back(R);
            }
        }
        int sz=cur.size();
        for (int j=0;j<sz;j++){
            ans.push_back({cur[j],tot++});
            cur.push_back(tot-1);
        }

    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first+1<<" "<<cur.second+1<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}