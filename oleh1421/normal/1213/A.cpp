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
    int tt=1;
    while (tt--){
         int n;cin>>n;
         int cnt=0;
         for (int i=1;i<=n;i++){
            int x;cin>>x;
            cnt+=x%2;
         }
         cout<<min(cnt,n-cnt);
    }


    return 0;
}


///2007521364118