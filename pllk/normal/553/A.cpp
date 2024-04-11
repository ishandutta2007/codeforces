#include <iostream>

using namespace std;

#define ll long long
#define M 1000000007

int k;
int c[1111];
int s[1111];

ll d[1111][1111];

int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        s[i] = s[i-1];
        s[i] += c[i];
    }
    for (int i = 0; i <= 1100; i++) d[i][0] = 1;
    for (int i = 1; i <= 1100; i++) {
        for (int j = 1; j <= i; j++) {
            d[i][j] = (d[i-1][j-1]+d[i-1][j])%M;
        }
    }
    ll t = 1;
    for (int i = 1; i <= k; i++) {
        t *= d[s[i]-1][c[i]-1];
        t %= M;
    }
    cout << t << "\n";
}