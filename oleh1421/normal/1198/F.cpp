#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
pair<int,int>a[1000001];
int ans[1000001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    int g=a[1].first;
    for (int i=2;i<=n;i++) g=__gcd(g,a[i].first);
    if (g>1){
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=100;i++){
        random_shuffle(a+1,a+n+1);
        int g=a[1].first;
        ans[a[1].second]=1;
        vector<int>v;
        for (int i=2;i<=n;i++){
            if (a[i].first%g==0){
                ans[a[i].second]=2;
                v.push_back(i);
            }
            else {
                ans[a[i].second]=1;
                g=__gcd(g,a[i].first);
            }
        }
        if (!v.empty() && g==1){
            int g1=a[v[0]].first;
            for (int i=1;i<v.size();i++){
                g1=__gcd(g1,a[v[i]].first);
            }
            if (g1==1){
                cout<<"YES\n";
                for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
                return 0;
            }
        }
    }
    cout<<"NO";

    return 0;
}