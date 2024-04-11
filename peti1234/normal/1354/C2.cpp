#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        double pi=3.141592653589793238;
        cout.precision(10);
        cout << cos(pi/(4*n))/sin(pi/(2*n)) << endl;
    }
    return 0;
}