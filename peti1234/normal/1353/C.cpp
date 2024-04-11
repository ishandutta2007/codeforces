#include <bits/stdc++.h>

using namespace std;
int w;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, n/=2;
        cout << n*(n+1)*(2*n+1)/6*8  << "\n";
    }
    return 0;
}