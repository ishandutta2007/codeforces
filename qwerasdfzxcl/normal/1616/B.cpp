#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    if (n==1) {cout << s[0] << s[0] << '\n'; return;}
    if (s[0]==s[1]) {cout << s[0] << s[0] << '\n'; return;}

    int ans = (int)s.size()-1;
    for (int i=0;i<(int)s.size()-1;i++){
        if (s[i]<s[i+1]) {ans = i; break;}
    }
    for (int i=0;i<=ans;i++) cout << s[i];
    for (int i=ans;i>=0;i--) cout << s[i];
    cout << '\n';
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