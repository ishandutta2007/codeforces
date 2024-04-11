#include <bits/stdc++.h>

using namespace std;
int w;
long long po=1, d, mod, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> d >> mod;
        sum=1, po=1;
        while(po<=d) {
            long long x=min(2*po, d+1);
            sum*=(x-po+1), sum%=mod;
            po=x;
        }
        cout << (sum+mod-1)%mod << "\n";
    }
    return 0;
}
// Elg knny b feladat volt.