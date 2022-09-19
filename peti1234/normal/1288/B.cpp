#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--) {
        long long a, b;
        cin >> a >> b;
        long long c=0;
        for (long long i=10; i<=INT_MAX; i*=10) {
            if (b>=i-1) {
                c++;
            }
        }
        cout << a*c << "\n";
    }
    return 0;
}