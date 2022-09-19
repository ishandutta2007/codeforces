#include <bits/stdc++.h>

using namespace std;
long long w, a, b, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        if (a==1) {
            a=n+1;
        }
        long long e=1;
        while (e<n) {
            if (e%b==n%b) {
                e=n;
            } else {
                e*=a;
            }
        }
        cout << (e==n ? "Yes" : "No") << "\n";
    }
    return 0;
}