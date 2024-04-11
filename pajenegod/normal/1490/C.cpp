#include <iostream>
#include <math.h>
 
using namespace std;
 
bool binarySearch(long long n1, long long l, long long r, long long x)
{
    if (r >= l) {
        long long mid = l + (r - l) / 2;
 
        double n13 = pow(n1, 3);
        double mid3 = pow(mid, 3);
 
        // Removing the follwing line will result in WA
        fmod(mid3,1);
 
        long long p = n13 + mid3;
 
        if (p == x) {
            return true;
        }
 
        if (p > x)
            return binarySearch(n1, l, mid - 1, x);
 
        return binarySearch(n1, mid + 1, r, x);
    }
 
    return false;
}
 
int main()
{
    long long t, x;
 
    cin >> t;
 
    while (t--) {
        cin >> x;
 
        bool found = false;
 
        for (int i = 1; i <= 10000; ++i) {
            if (binarySearch(i, i, 10000, x) == true) {
                found = true;
 
                break;
            }
        }
 
        if (found) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
    return 0;
}