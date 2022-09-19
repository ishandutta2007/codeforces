#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, p=0, k--;
        for (int i=2; i<=sqrt(n); i++) if (n%i==0) {n+=i, p=1; break;}
        if (!p) n*=2;
        cout << n+2*k << "\n";
    }
    return 0;
}