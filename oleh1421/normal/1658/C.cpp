#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
int c[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>c[i];
    int pos=-1;
    for (int i=0;i<n;i++){
        if (c[i]==1){
            if (pos!=-1){
                cout<<"NO\n";
                return;
            }
            pos=i;
        }
    }
    if (pos==-1){
        cout<<"NO\n";
        return;
    }
    for (int i=1;i<n;i++){
        if (c[(pos+i-1)%n]+1<c[(pos+i)%n]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2


//
//1 2

/**

**/