#include <bits/stdc++.h>

using namespace std;
int n;
long double x, sum;
long long sum2;
int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        int kx=x;
        if (x<0) kx--;

        sum+=x;
        sum2+=kx;

        if (sum2+1e-6<sum) {
            kx++;
            sum2++;
        }
        cout << kx << " ";
    }
    cout << "\n";
    return 0;
}