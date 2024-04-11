#include <bits/stdc++.h>

using namespace std;
long long w, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        long long sum=n*(n+1)/2;
        for (int po=1; po<=n; po*=2) {
            sum-=2*po;
        }
        cout << sum << "\n";
    }
    return 0;
}