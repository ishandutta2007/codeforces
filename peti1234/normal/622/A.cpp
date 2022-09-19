#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int i=1; ; i++) {
        if (n>i) n-=i;
        else {
            cout << n << "\n";
            return 0;
        }
    }
    return 0;
}