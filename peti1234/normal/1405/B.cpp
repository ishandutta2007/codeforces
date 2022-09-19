#include <bits/stdc++.h>

using namespace std;
long long maxi, n, w, sum;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, maxi=0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            sum-=x, maxi=max(maxi, sum);
        }
        cout << maxi << "\n";
    }
    return 0;
}