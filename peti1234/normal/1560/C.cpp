#include <bits/stdc++.h>

using namespace std;
int w;
long long n, s, dif;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        s=sqrt(n-1), dif=n-s*s;
        if (dif<=s+1) {
            cout << dif << " " << s+1 << "\n";
        } else {
            cout << s+1 << " " << 2*s+2-dif << "\n";
        }

    }
    return 0;
}