#include <bits/stdc++.h>

using namespace std;
long long a, b, c, ans=1e18;
set<long long> o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    c=a+b;
    for (long long i=1; i*i<=c; i++) {
        if (c%i==0) {
            o.insert(c/i);
        }
    }
    for (int s=0; s<2; s++) {
        for (long long i=1; i*i<=a; i++) {
            if (a%i==0) {
                auto kov=o.lower_bound(a/i);
                long long ert=*kov;
                if (i<=c/ert) {
                    ans=min(ans, ert+c/ert);
                }
            }
        }
        swap(a, b);
    }
    cout << 2*ans << "\n";
    return 0;
}
/*
100000000000000
100000000000000
*/