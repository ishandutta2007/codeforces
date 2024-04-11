#include <bits/stdc++.h>

using namespace std;
int n, k;
bool jo(int a, int b) {
    return (__builtin_popcount(a)<=b && b<=a);
}
int main()
{
    cin >> n >> k;
    if (!jo(n, k)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int po=1;
    while (k) {
        while (jo(n-po, k-1)) {
            cout << po << " ";
            n-=po, k--;
        }
        po*=2;
    }
    return 0;
}