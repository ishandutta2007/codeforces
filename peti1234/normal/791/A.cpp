#include <bits/stdc++.h>

using namespace std;
long long a, b;
int k;
int main()
{
    cin >> a >> b;
    while (a<=b) {
        a*=3;
        b*=2;
        k++;
    }
    cout << k << endl;
    return 0;
}