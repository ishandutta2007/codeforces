#include <iostream>

using namespace std;

#define ll long long
#define M 1000000007

int n, k;

ll pot(ll x, int n) {
    if (n == 0) return 1;
    if (n%2 == 1) return (pot(x,n-1)*x)%M;
    ll t = pot(x,n/2);
    return (t*t)%M;
}

ll inv(ll x) {
    return pot(x, M-2);
}

ll z[101010];
ll z2[101010];
ll ss;

string s;

int main() {
    cin >> n >> k;
    if (k == 0) {
        cin >> s;
        ll tt = 0;
        for (int i = 0; i < s.size(); i++) {
            tt = 10*tt+s[i]-'0';
            tt %= M;
        }
        cout << tt << "\n";
        return 0;
    }
    ll t = 1;
    for (int i = 1; i <= n-2; i++) t = (t*i)%M;
    for (int i = 1; i <= k-1; i++) t = (t*inv(i))%M;
    for (int i = 1; i <= (n-2)-(k-1); i++) t = (t*inv(i))%M;
    z[0] = t;
    int c = (n-2)-(k-1);
    int k = 0;
    for (int i = n-2; i >= 1; i--) {
        t = (t*inv(i))%M;
        t = (t*c)%M;
        c--;
        k++;
        z[k] = t;
    }
    ll u = 1;
    for (int i = 0; i < n; i++) {
        z2[i] = u;
        u = (u*10)%M;
        ss += z[i]*z2[i];
        ss %= M;
    }
    cin >> s;
    ll tt = 0;
    for (int i = 0; i < n; i++) {
        if (n-i <= k) {
            ss -= z[n-i]*z2[n-i];
            ss %= M;
            if (ss < 0) ss += M;
            ss -= z[n-i-1]*z2[n-i-1];
            ss %= M;
            if (ss < 0) ss += M;
            z[n-i-1] += z[n-i];
            z[n-i-1] %= M;
            ss += z[n-i-1]*z2[n-i-1];
            ss %= M;
        }
        tt += (s[i]-'0')*ss;
        tt %= M;
    }
    cout << tt << "\n";
}