//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=100010;

void solve(){
    string s;cin>>s;
    int last=-2;
    bool was=false;
    for (int i=0;i<s.size();i++){
        if (last+1==i){
            if (was && s[i]=='0'){
                cout<<"NO\n";
                return;
            }
            if (s[i]=='1') was=true;
            continue;
        }
        if (!was){
            if (s[i]=='1') last=i;
        } else {
            if (s[i]=='0') last=i;
        }
    }
    cout<<"YES\n";
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}