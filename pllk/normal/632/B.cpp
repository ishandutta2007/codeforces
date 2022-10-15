#include <iostream>

using namespace std;

typedef long long ll;

int n;
int p[505050];
string s;
ll s1[505050];
ll s2[505050];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> s;
    s = "*"+s;
    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i-1];
        s2[i] = s2[i-1];
        if (s[i] == 'A') s1[i] += p[i];
        else s2[i] += p[i];
    }
    ll t = s1[n];
    for (int i = 1; i <= n; i++) {
        ll u1 = s2[i]+s1[n]-s1[i];
        ll u2 = s1[i]+s2[n]-s2[i];
        t = max(t,u1);
        t = max(t,u2);
    }
    cout << t << "\n";
}