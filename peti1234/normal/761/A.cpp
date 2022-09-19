#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int main()
{

    cin >> b >> a;
    if (a==0 && b==0) {
        cout << "NO";
         return 0;
    }
    if (a-b>=-1 && a-b<=1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}