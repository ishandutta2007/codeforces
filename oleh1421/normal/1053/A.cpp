#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    if ((2ll*n*m)%k){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    cout<<0<<" "<<0<<endl;
    ll a=(2ll*n*m)/k;
    vector<int>v;
    n*=2;
    for (int i=1;i*i<=n;i++){
        if (n%i) continue;
        v.push_back(i);
        if (i*i<n) v.push_back(n/i);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i:v){
        if (i*2>n) continue;
        if (a%i==0){
            cout<<0<<" "<<a/i<<endl;
            cout<<i<<" "<<0<<endl;
            return 0;
        }
    }
    return 0;
}
/*
7
0110010
1 2
1 3
1 4
2 5
2 6
3 7
*/