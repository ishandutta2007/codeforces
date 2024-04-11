#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, lo=0, hi=2e9, mid;
    cin >> n;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        long long ert=(mid-1)/2+(mid-4)/4;
        if (ert>=n) hi=mid;
        else lo=mid;
    }
    cout << hi << "\n";
    return 0;
}