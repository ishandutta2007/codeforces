#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long a, b, ans=0;
    cin >> a >> b;
    for (long long i=1; i<a; i++) {
        for (long long j=1; j<b; j++) {
            ans+=min(i, a-i)*min(j, b-j);
        }
    }
    cout << ans << "\n";
    return 0;
}