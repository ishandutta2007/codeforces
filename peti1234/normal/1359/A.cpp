#include <bits/stdc++.h>

using namespace std;
int w, n, m, k;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m >> k;
        if (m<=n/k) cout << m << "\n";
        else {
            int p=n/k;
            m-=n/k, n-=n/k, k--;
            cout << p-(m-1)/k-1 << "\n";
        }
    }
    return 0;
}