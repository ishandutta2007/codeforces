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
        cout << 1/tan(pi/(2*n)) << endl;
    }
    return 0;
}