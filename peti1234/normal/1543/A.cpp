#include <bits/stdc++.h>

using namespace std;
long long w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if (a>b) {
            swap(a, b);
        }
        long long dif=b-a;
        if (!dif) {
            cout << 0 << " " << 0 << "\n";
        } else {
            cout << dif << " " << min(a%dif, dif-a%dif) << "\n";
        }
    }
    return 0;
}