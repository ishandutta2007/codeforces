#include <bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    cin >> n;
    for (long long i=2; i<=1'000'000; i++) {
        while (n%(i*i)==0) {
            n/=i;
        }
    }
    cout << n << "\n";
    return 0;
}