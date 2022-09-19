#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1; i<n; i+=2) {
        cout << i << " ";
    }
    if (n%2) {
        cout << n << " ";
    }
    for (int i=n-n%2-1; i>=1; i-=2) {
        cout << i << " ";
    }
    for (int i=2; i<n; i+=2) {
        cout << i << " ";
    }
    if (n%2==0) {
        cout << n << " ";
    }
    for (int i=n-2+n%2; i>=2; i-=2) {
        cout << i << " ";
    }
    cout << n << "\n";
    return 0;
}