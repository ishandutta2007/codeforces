//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int>v;
    v.resize(n);
    for (int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int cnt=0;
    for (int i=0;i<n;i++){
        if (v[i]==0) continue;
        for (int j=i+1;j<n;j++){
            if (v[j]%v[i]==0) v[j]=0;
        }
        v[i]=0;
        cnt++;
    }
    cout<<cnt;
    return 0;
}