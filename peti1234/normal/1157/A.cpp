#include <bits/stdc++.h>

using namespace std;
int n, db=9;
int main()
{
    cin >> n;
    while (n>9) {
        db++;
        n++;
        while (n%10==0) {
            n/=10;
        }
    }
    cout << db << "\n";
    return 0;
}