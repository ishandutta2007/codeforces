#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, maxi=0;
bool v=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, v=0, maxi=0;
        for (int i=1; i<=sqrt(n); i++) {
            if (n%i==0 && n/i<=k && !v) cout << i << "\n", v=true;
            if (n%i==0 && i<=k) maxi=n/i;
        }
        if (!v) cout << maxi << "\n";
    }
    return 0;
}