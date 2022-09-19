#include <bits/stdc++.h>

using namespace std;
long long k;
long long q=999999;
long long p;
long long x;
int main()
{
    cin >> k;
    x=k%2000;
    p=2000-x;
    k+=p;
    while(k/2000>=p) {
        k+=2000;
        p+=2000;
    }
    cout << 2000 << endl;
    for (int i=1; i<=1998; i++) {
        cout << 0 << " ";
    }
    cout << k/2000-p << " ";
    cout << p << endl;
    return 0;
}