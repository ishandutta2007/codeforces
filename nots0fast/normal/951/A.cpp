#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

char s[100100];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    n = strlen(s);
    int tlen = 1;
    int ans = 0;
    char l = s[0];
    for(int i=0; i<n; ++i) {
        ans = max(ans, tlen);
        if(s[i] != l) {
            tlen++;
            ans = max(ans, tlen);
        } else {
            tlen = 1;
        }
        l = s[i];
    }
    if(s[0] == s[n-1]) {
        cout << ans << endl;
        return 0;
    }
    l = 0;
    int flen = 0;
    for(int i=0; i<n; ++i) {
        if(l != s[i]) {
            ++flen;
        } else {
            break;
        }
        l = s[i];
    }
    int llen = 0;
    l = 0;
    for(int i=n-1; i>=flen; --i) {
        if(l != s[i]) {
            ++llen;
        } else break;
        l = s[i];
    }
    cout << max(ans, flen+llen) << endl;
    return 0;
}