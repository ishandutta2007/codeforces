#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long n, dif, l, r;
        cin >> n >> dif >> l >> r;
        cout << n/dif-r/dif+(l-1)/dif << "\n";
    }
    return 0;
}