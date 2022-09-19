#include <bits/stdc++.h>

using namespace std;
int n, a=1, b=2;
int main()
{
    cin >> n;
    while(n>b) {
        if (a%2) a=2*b;
        else a=2*b-1;
        b=a+1;
    }
    cout << (a==n || b==n) << "\n";
    return 0;
}