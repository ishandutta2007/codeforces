#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    string s;
    cin >> s;
    if (s.back()=='A') {cout << "NO\n"; return;}
    int tmp = 0;
    for (int i=(int)s.size()-1;i>=0;i--){
        if (s[i]=='B'){
            tmp++;
            continue;
        }
        tmp = max(tmp-1, 0);
    }
    if (tmp==0) cout << "YES\n";
    else cout << "NO\n";
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