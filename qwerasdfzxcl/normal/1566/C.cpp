#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    string s[2];
    int n;
    cin >> n;
    cin >> s[0] >> s[1];
    ll ans = 0, prv = -1;
    for (int i=0;i<n;i++){
        if (s[0][i]==s[1][i]){
            if (s[0][i]=='0'){
                if (prv==3) ans += 2, prv = -1;
                else ans++, prv = 0;
            }
            else{
                if (prv==0) ans++, prv = -1;
                else prv = 3;
            }
        }
        else{
            ans += 2;
            prv = 2;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}