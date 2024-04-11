#include <bits/stdc++.h>
 
using namespace std;
long long n;
int main()
{
    cin >> n;
    for (long long i=2; i<=sqrt(n); i++) {
        if (n%i==0) {
            while(!(n%i)) {
                n/=i;
            }
            if (n!=1) {
                cout << 1 << "\n";
                return 0;
            }
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}