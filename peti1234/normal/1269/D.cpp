#include <bits/stdc++.h>

using namespace std;
long long b, w, n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (i%2) w+=x/2, b+=x-x/2;
        if (!(i%2)) b+=x/2, w+=x-x/2;
    }
    cout << min(b, w);
    return 0;
}