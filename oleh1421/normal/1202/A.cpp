#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[200001];
int cnt[200001];
int N=10000;
void solve(){
     string x;cin>>x;
     string y;cin>>y;
     reverse(x.begin(),x.end());
     reverse(y.begin(),y.end());
     int fi=-1;
     for (int i=0;i<y.size();i++){
        if (y[i]=='1'){
            fi=i;
            break;
        }
     }
     for (int i=fi;i<x.size();i++){
         if (x[i]=='1'){
            cout<<i-fi;
            return;
         }
     }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
        cout<<endl;
    }
    return 0;
}