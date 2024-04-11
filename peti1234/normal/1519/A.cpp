#include <bits/stdc++.h>

using namespace std;
long long w, a, b, dif;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> dif;
        if (a>b) {
            swap(a, b);
        }
        cout << (a*(dif+1)>=b ? "YES" : "NO") << "\n";
    }
    return 0;
}