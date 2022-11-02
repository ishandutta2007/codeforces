#include <iostream>

using namespace std;
typedef long long ll;
const int LIM = 20;

int main()
{
    int a[LIM], k;
    ll x;
    cin >> x >> k;
    int cnt = 0;
    while (x != 0) cnt++, a[cnt] = x % 10, x /= 10;
    for (int i = cnt; i >= 1; i--) for (int j = 9; j > a[i]; j--)
    {
        int nom = -1;
        for (int o = 1; o < i; o++) if (a[o] == j) nom = o;
        if (nom == -1 || i - nom > k) continue;
        k -= i - nom;
        for (int o = nom; o < i; o++) swap(a[o], a[o + 1]);
    }
    for (int i = cnt; i >= 1; i--) cout << a[i];
    return 0;
}