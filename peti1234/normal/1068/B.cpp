#include <bits/stdc++.h>

using namespace std;
long long a, db;
int main()
{
    cin >> a;
    for (long long i=1; i*i<=a; i++) {
        if (a%i==0) db+=2;
        if (i*i==a) db--;
    }
    cout << db << "\n";
    return 0;
}