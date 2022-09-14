#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
         int n;cin>>n;
         for (int i=n;i>=1;i--) cin>>a[i];
         int minx=1000001;
         int cnt=0;
         for (int i=1;i<=n;i++){
             if (minx<a[i]) cnt++;
             else minx=a[i];
         }
         cout<<cnt<<endl;
    }


    return 0;
}


///2007521364118