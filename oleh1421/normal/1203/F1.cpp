#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
     if (a.second<0 && b.second>=0) return false;
     if (a.second>=0 && b.second<0) return true;
     if (a.second>=0 && b.second>=0) return a.first<b.first;
     return (a.first+a.second>b.first+b.second);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,r;cin>>n>>r;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
        int cur=r;
        bool ok=true;
        for (int j=0;j<n;j++){
            if (cur<v[j].first){
                ok=false;
                break;
            }
            cur+=v[j].second;
        }
        if (cur<0) ok=false;
        if (ok){
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}