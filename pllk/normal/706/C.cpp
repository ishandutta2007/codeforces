#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define A 999999999999999LL

int n;
ll c[101010];
string s[101010];
string s2[101010];
ll d[101010][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
        s2[i] = s[i];
        reverse(s2[i].begin(),s2[i].end());
    }
    d[1][0] = 0;
    d[1][1] = c[1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = A;
        d[i][1] = A;
        if (s[i-1] <= s[i]) d[i][0] = min(d[i][0],d[i-1][0]);
        if (s2[i-1] <= s[i]) d[i][0] = min(d[i][0],d[i-1][1]);
        if (s[i-1] <= s2[i]) d[i][1] = min(d[i][1],d[i-1][0]+c[i]);
        if (s2[i-1] <= s2[i]) d[i][1] = min(d[i][1],d[i-1][1]+c[i]);
    }
    ll u = min(d[n][0],d[n][1]);
    if (u == A) cout << "-1\n";
    else cout << u << "\n";
}