#include <bits/stdc++.h>

using namespace std;
int w, a, b, sum, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> n, sum=1;
        while(a%2==0) {
            a/=2, sum*=2;
        }
        while(b%2==0) {
            b/=2, sum*=2;
        }
        cout << (sum>=n ? "YES" : "NO") << "\n";
    }
    return 0;
}