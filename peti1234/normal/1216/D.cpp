#include <bits/stdc++.h>

using namespace std;
long long n, maxi, sum, s, el;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        maxi=max(maxi, x);
        if (i>1) s=__gcd(s, abs(el-x));
        sum+=x;
        el=x;
    }
    cout << (n*maxi-sum)/s << " " << s << "\n";
    return 0;
}