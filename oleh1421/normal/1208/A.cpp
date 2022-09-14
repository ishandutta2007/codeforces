#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[101][101];
int b[101][101];
int32_t main() {
    int tt;cin>>tt;
    while (tt--){
        int a,b,c;cin>>a>>b>>c;
        if (c%3==0) cout<<a;
        else if (c%3==1) cout<<b;
        else cout<<(a^b);
        cout<<endl;
    }
    return 0;
}


///2007521364118