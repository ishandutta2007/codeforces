#include <bits/stdc++.h>

using namespace std;
int w, n;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0;
        if (n%4) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i=1; i<=n/2; i++) cout << 2*i << " ", sum+=2*i;
            for (int i=1; i<n/2; i++) cout << 2*i-1 << " ", sum-=2*i-1;
            cout << sum << "\n";
        }
    }
    return 0;
}