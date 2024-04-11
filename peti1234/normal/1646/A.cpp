#include <bits/stdc++.h>

using namespace std;
long long w, n, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        cout << s/(n*n) << "\n";
    }
    return 0;
}