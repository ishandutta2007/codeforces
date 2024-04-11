#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool chk(int x, int y, string &s, string &t){
    for (int i=0;i<=y;i++){
        if (s[x+i]!=t[i]) return 0;
    }
    for (int i=y+1;i<(int)t.size();i++){
        int j = i-y;
        if (x+y-j<0 || s[x+y-j]!=t[i]) return 0;
    }
    return 1;
}

void solve(){
    string s, t;
    cin >> s >> t;
    bool ans = 0;
    for (int i=0;i<(int)t.size();i++){
        for (int j=0;j<(int)s.size();j++){
            if (j+i>=(int)s.size()) break;
            ans |= chk(j, i, s, t);
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
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