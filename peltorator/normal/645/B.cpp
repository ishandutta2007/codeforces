#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    long long n,k,i,ans=0;

    cin >> n >> k;

    if (k>=n/2) cout << n*(n-1)/2;
    else cout << 2*k*(n-2*k)+k*(2*k-1);

    return 0;
}