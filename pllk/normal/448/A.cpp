#include <iostream>

using namespace std;

int a1, a2, a3;
int b1, b2, b3;
int n;
int a, b;
int u;

int main() {
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    a = a1+a2+a3;
    b = b1+b2+b3;
    if (a == 0) goto lol1;
    u += a/5;
    if (a%5 != 0) u++;
    lol1:
    if (b == 0) goto lol2;
    u += b/10;
    if (b%10 != 0) u++;
    lol2:
    if (u <= n) cout << "YES\n";
    else cout << "NO\n";
}