#include <bits/stdc++.h>

using namespace std;
long long w, n, a, b, pos, x, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        for (int i=1; i<=n; i++) {
            cin >> x;
            sum+=b*(x-pos);
            if ((n-i)*b>=a) {
                sum+=a*(x-pos);
                pos=x;
            }
        }
        cout << sum << "\n";
        sum=0, pos=0;
    }
    return 0;
}