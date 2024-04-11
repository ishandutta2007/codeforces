#include <bits/stdc++.h>

using namespace std;
const int sok=1e9;
int n, sum, a=-sok, b=sok, x;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x>0) {
            sum+=x;
            if (x%2) {
                b=min(b, x);
            }
        } else if (x%2) {
            a=max(a, x);
        }
    }
    if (sum%2==0) {
        sum-=min(b, -a);
    }
    cout << sum << "\n";
    return 0;
}