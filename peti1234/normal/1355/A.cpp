#include <bits/stdc++.h>

using namespace std;
long long w, n, k, a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k, a=9;
        while(k>1 && a>0) {
            long long p=n; a=9, b=0;
            while(p) a=min(a, p%10), b=max(b, p%10), p/=10;
            k--, n+=a*b;
        }
        cout << n << "\n";
    }
    return 0;
}