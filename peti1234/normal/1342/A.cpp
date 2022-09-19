#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        if (b>a) swap(a, b);
        cout << (a-b)*c+b*min(2*c, d) << "\n";
    }
    return 0;
}