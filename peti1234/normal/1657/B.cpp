#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n, b, x, y;
    cin >> w;
    while (w--) {
        cin >> n >> b >> x >> y;
        int a=0;
        long long sum=0;
        for (int i=1; i<=n; i++) {
            if (a+x<=b) a+=x;
            else a-=y;
            sum+=a;
        }
        cout << sum << "\n";
    }
    return 0;
}