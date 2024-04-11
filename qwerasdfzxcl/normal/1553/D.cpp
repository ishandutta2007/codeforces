#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;
    int pt = -1e9, cur = 0;
    int tmp = -1;
    for (int i=0;i<(int)s.size();i++){
        if (pt==-1e9){
            if (s[i]==t[0]) pt = i, cur = 1, tmp = pt%2;
            continue;
        }
        if (cur==(int)t.size()) break;
        if (s[i]==t[cur] && ((i-pt)%2==1 || i-pt==1)) pt = i, cur++;
    }
    bool ans = (cur==(int)t.size() && ((int)s.size()-pt-1)%2==0);

    pt = -1e9, cur = 0;

    for (int i=0;i<(int)s.size();i++){
        if (pt==-1e9){
            if (s[i]==t[0] && i%2!=tmp) pt = i, cur = 1;
            continue;
        }
        if (cur==(int)t.size()) break;
        if (s[i]==t[cur] && ((i-pt)%2==1 || i-pt==1)) pt = i, cur++;
    }
    if (ans || (cur==(int)t.size() && ((int)s.size()-pt-1)%2==0)) cout << "YES\n";
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