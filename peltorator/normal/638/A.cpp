#include <iostream>

using namespace std;

int main()
{
    long long n,a;

    cin >> n >> a;

    if (a % 2 == 1) cout << (a+1)/2;
    else cout << (n+2-a)/2;

    return 0;
}