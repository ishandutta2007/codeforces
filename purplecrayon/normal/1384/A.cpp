#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e2+10;

int n, a[MAXN];

void solve(){
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 200; i++) s += 'a';
    for (int i = 0; i < n; i++){
        cout << s << "\n";
        s[a[i]] = (s[a[i]] > 'a' ? s[a[i]]-1 : s[a[i]]+1);
    }
    cout << s << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}