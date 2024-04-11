#include <bits/stdc++.h>

using namespace std;
int n, x, el, maxi, cnt;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (el>=x) cnt=0;
        cnt++;
        el=x;
        maxi=max(maxi, cnt);
    }
    cout << maxi << "\n";
    return 0;
}