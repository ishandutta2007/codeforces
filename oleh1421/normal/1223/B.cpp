#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
int a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        string a,b;cin>>a>>b;
        int mask1=0,mask2=0;
        for (auto i:a){
            mask1|=(1<<(i-'a'));
        }
        for (auto i:b){
            mask2|=(1<<(i-'a'));
        }
        if ((mask1&mask2)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
/*



*/