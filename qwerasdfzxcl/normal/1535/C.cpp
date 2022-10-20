#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    string s;
    cin >> s;
    int prv = -1, cur = 0;
    ll ans = 0;
    for (int i=0;i<(int)s.size();i++){
        if (s[i]=='?'){
            cur++; ans += cur;
            continue;
        }
        if (prv==-1){
            cur++; ans += cur; prv = i;
            continue;
        }
        if (((s[i]-s[prv])&1)==((i-prv)&1)){
            cur++; ans += cur;
        }
        else{
            cur = i-prv; ans += cur;
        }
        prv = i;
    }
    printf("%lld\n", ans);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}