#include <bits/stdc++.h>

using namespace std;
long long n, s, ans, k=200, o;
int main()
{
    cin >> n >> s;
    ans=max(o, n-(s+k));
    for (long long i=s; i<=min(n, s+k); i++) {
        long long sum=0, ii=i;
        while (ii) {
            sum+=ii%10;
            ii/=10;
        }
        if (i-sum>=s) ans++;
    }
    cout << ans << "\n";
    return 0;
}