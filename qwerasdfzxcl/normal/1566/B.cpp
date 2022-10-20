#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i=0;i<n;i++) if (s[i]=='0'){
        if (!i || s[i-1]!='0') cnt++;
    }
    if (cnt>=2) printf("2\n");
    else{
        for (int i=0;i<n;i++) if (s[i]=='0'){
            printf("1\n");
            return;
        }
        printf("0\n");
    }
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