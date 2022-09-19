#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    cout << n << " ";
    for (int i=2; i<=n; i++) {
        while(n%i==0) n/=i, cout << n << " ";
    }
}