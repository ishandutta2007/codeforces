#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
const long long mod=1000000007ll;
int d[200002];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>d[i];
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) v.push_back({d[i],i});
    sort(v.begin(),v.end());
    vector<int>ord;
    for (auto cur:v) ord.push_back(2*cur.second-1);
    reverse(ord.begin(),ord.end());
    vector<pair<int,int> >ans;
    for (int i=1;i<n;i++) ans.push_back({ord[i-1],ord[i]});
    ///d[ord[0]]-1
    ans.push_back({ord[d[(ord[0]+1)/2]-1],ord[0]+1});
    if (d[(ord[0]+1)/2]==n) ord.push_back(ord[0]+1);
    for (int i=1;i<n;i++){
        int v=ord[i];
        int v1=v+1;
        int pr=ord[i-1];
        int pr1=pr+1;
        int to=i+d[(v+1)/2]-1;
        if (to==(int)ord.size()-1){
            ord.push_back(v1);
        }
        ans.push_back({v1,ord[to]});
    }
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;
}