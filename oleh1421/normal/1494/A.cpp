//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//typedef __int128 ll;
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=100010;
const int K=10010;
const ll inf=1e18+1ll;
void solve(){
    string s;cin>>s;
    for (int i:{-1,1}){
        for (int j:{-1,1}){
            for (int t:{-1,1}){
                int sum=0;
                bool ok=true;
                for (auto cur:s){
                    if (cur=='A') sum+=i;
                    else if (cur=='B') sum+=j;
                    else sum+=t;
                    if (sum<0){
                        ok=false;
                    }
                }
                if (sum) ok=false;
                if (ok){
                    cout<<"YES\n";
                    return;
                }
            }
        }
    }
    cout<<"NO\n";
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