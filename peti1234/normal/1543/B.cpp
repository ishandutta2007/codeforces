#include <bits/stdc++.h>

using namespace std;
long long w, n, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sum+=x;
        }
        long long s=sum%n;
        cout << s*(n-s) << "\n";
    }
    return 0;
}