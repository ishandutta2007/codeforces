#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        long long koz=(n+2)/3+1;
        n-=koz;
        long long bal=(n+2)/2, jobb=(n-1)/2;
        cout << bal << " " << koz << " " << jobb << "\n";
    }
    return 0;
}