#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline ll gcd(ll a, ll b) {
    ll r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    while(n > 0) {
        n--;
        ll p, q, b;
        cin >> p >> q >> b;
        q = q / gcd(p, q);
        b = gcd(q, b);
        while(b > 1) {
            while(q % b == 0)
                q /= b;
            b = gcd(b, q);
        }
        if(q == 1)
            cout << "Finite";
        else
            cout << "Infinite";
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}