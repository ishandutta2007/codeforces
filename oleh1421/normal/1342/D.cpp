#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
int c[N];
int cnt[N];
vector<int>ans[N];
int n,k;
bool ok(int x){
    if (x==0) return false;
    for (int i=0;i<x;i++){
        vector<int>v;
        for (int j=i;j<n;j+=x){
            v.push_back(a[j]);
        }
        reverse(v.begin(),v.end());
        for (int j=0;j<v.size();j++){
            if (j+1>c[v[j]]) {

                return false;
            }
        }

    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>c[i];
    sort(a,a+n);
    int l=0;
    int r=n;
    while (r-l>1){
        int m=(l+r)/2;
        if (ok(m)) r=m;
        else l=m;
    }
    cout<<r<<endl;
    for (int i=0;i<n;i++){
        ans[i%r].push_back(a[i]);
    }
    for (int i=0;i<r;i++){
        cout<<ans[i].size()<<" ";
        for (auto j:ans[i]) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}