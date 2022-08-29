#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main ()
{
    long long A, B;
    cin >> A >> B;

    long long L = A / __gcd (A, B) * B;
    long long AC = L / A, BC = L / B;

    if (A < B)
        AC--;
    else
        BC--;

    if (AC > BC)
        puts ("Dasha");
    else if (AC < BC)
        puts ("Masha");
    else
        puts ("Equal");

    return 0;
}