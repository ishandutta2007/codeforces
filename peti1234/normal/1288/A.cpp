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
        long long c=a/2;
        a=a-c;
        c++;
        if (a*c>=b) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}